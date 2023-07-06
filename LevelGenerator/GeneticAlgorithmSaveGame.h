#pragma once
#include "GameFramework/SaveGame.h"
#include "Chromosome.h"
#include "Population.h"
#include "GeneticAlgorithmSaveGame.generated.h"

UCLASS()

class MAGICDEFENSE_API UGeneticAlgorithmSaveGame : public USaveGame
{
    GENERATED_BODY()

public:
    UGeneticAlgorithmSaveGame();

public:

    UPROPERTY(VisibleAnywhere, Category = "SaveGame")
        FString PlayerName;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SaveGame")
        FString SaveSlotName;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SaveGame")
        int32 UserIndex;

    UPROPERTY(VisibleAnywhere, Category = "SaveGame")
        int32 LastFailures;

    UPROPERTY(VisibleAnywhere, Category = "SaveGame")
        APopulation* Population;

    UPROPERTY(VisibleAnywhere, Category = "SaveGame")
        float StartTime;

    UPROPERTY(VisibleAnywhere, Category = "SaveGame")
        float DifficultyFactor;

    UPROPERTY(VisibleAnywhere, Category = "SaveGame")
        float LastBestFitness;

    UPROPERTY(VisibleAnywhere, Category = "SaveGame")
        int32 NonImprovingGens;

    UPROPERTY(VisibleAnywhere, Category = "SaveGame")
        bool bTerminate;

    UPROPERTY(VisibleAnywhere, Category = "SaveGame")
        int32 MaxPopulationSize;
    UPROPERTY()
        TArray<AChromosome*> Chromosomes;
    UPROPERTY()
        AChromosome* BestChromosome;


    virtual void Serialize(FArchive& Ar) override;
};



