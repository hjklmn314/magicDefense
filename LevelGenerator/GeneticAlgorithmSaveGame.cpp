#include "GeneticAlgorithmSaveGame.h"
#include "Serialization/MemoryWriter.h"
#include "Serialization/MemoryReader.h"
#include "UObject/PropertyPortFlags.h"


UGeneticAlgorithmSaveGame::UGeneticAlgorithmSaveGame()
{
    SaveSlotName = TEXT("GeneticAlgorithmSave");
    UserIndex = 0;
}

void UGeneticAlgorithmSaveGame::Serialize(FArchive& Ar)
{
    // Serialize basic information 
    Ar << PlayerName;
    Ar << LastFailures;
    Ar << Population;
    Ar << StartTime;
    Ar << DifficultyFactor;
    Ar << LastBestFitness;
    Ar << NonImprovingGens;
    Ar << bTerminate;

    if (Ar.IsSaving())
    {
        // Get the serialized size of each chromosome
        UE_LOG(LogTemp, Warning, TEXT("UGeneticAlgorithmSaveGame::Serialize!IsSavin"));
        TArray<int32> ChromosomeSerializedSizes;
        for (auto Chromosome : Chromosomes)
        {
            UE_LOG(LogTemp, Warning, TEXT("UGeneticAlgorithmSaveGame::Serialize!Chromosome"));
            TArray<uint8> Bytes;
            FMemoryWriter MemoryWriter(Bytes, true);
            FObjectProperty* Property = FindFProperty<FObjectProperty>(Chromosome->GetClass(), "Chromosome");
            Property->SerializeItem(FStructuredArchiveFromArchive(Ar).GetSlot(), Chromosome, Chromosome);
            int32 Size = Bytes.Num();
            ChromosomeSerializedSizes.Add(Size);
        }

        // Write the serialized sizes of each chromosome and their serialized data
        Ar << ChromosomeSerializedSizes;
        UE_LOG(LogTemp, Warning, TEXT("UGeneticAlgorithmSaveGame::Serialize!Write the serialized sizes of each chromosome and their serialized data"));
        for (auto Chromosome : Chromosomes)
        {
            TArray<uint8> Bytes;
            FMemoryWriter MemoryWriter(Bytes, true);
            FObjectProperty* Property = FindFProperty<FObjectProperty>(Chromosome->GetClass(), "Chromosome");
            Property->SerializeItem(FStructuredArchiveFromArchive(Ar).GetSlot(), Chromosome, Chromosome);
            Ar.Serialize(Bytes.GetData(), Bytes.Num());
        }
    }
    else
    {
        // Read the serialized sizes of each chromosome
        TArray<int32> ChromosomeSerializedSizes;
        Ar << ChromosomeSerializedSizes;

        // Read the serialized data of each chromosome, deserialize it into objects, and add them to the population
        UE_LOG(LogTemp, Warning, TEXT("UGeneticAlgorithmSaveGame::Serialize!Read the serialized data of each chromosome, deserialize it into objects, and add them to the population"));
        for (auto Size : ChromosomeSerializedSizes)
        {
            TArray<uint8> Bytes;
            Bytes.SetNum(Size);
            Ar.Serialize(Bytes.GetData(), Bytes.Num());
            FMemoryReader MemoryReader(Bytes, true);
            FObjectProperty* Property = FindFProperty<FObjectProperty>(AChromosome::StaticClass(), "Chromosome");
            FString BytesString;
            for (uint8 Byte : Bytes)
            {
                BytesString.AppendInt(Byte);
            }
            AChromosome* Chromosome = Cast<AChromosome>(StaticFindObjectFast(AChromosome::StaticClass(), nullptr, FName(*BytesString)));
            if (Chromosome == nullptr)
            {
                Chromosome = NewObject<AChromosome>();
                Property->SerializeItem(FStructuredArchiveFromArchive(Ar).GetSlot(), Chromosome, Chromosome);
                Chromosome->Rename(*Chromosome->GetName(), nullptr, REN_DontCreateRedirectors | REN_NonTransactional | REN_ForceNoResetLoaders);
            }
            Chromosomes.Add(Chromosome);
        }
    }
    UE_LOG(LogTemp, Warning, TEXT("UGeneticAlgorithmSaveGame::Serialize!Save completed"));
}
