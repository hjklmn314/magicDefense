#include "Population.h"

    // Sets default values
    APopulation::APopulation()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APopulation::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void APopulation::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

int32 APopulation::GetPopulationSize() const
{
    return PopulationSize;
}

void APopulation::SetPopulationSize(int32 NewSize)
{
    PopulationSize = NewSize;
}

int32 APopulation::GetChromosomeLength() const
{
    return ChromosomeLength;
}

void APopulation::SetChromosomeLength(int32 NewLength)
{
    ChromosomeLength = NewLength;
}

void APopulation::GetGeneBounds(float& OutLowerBound, float& OutUpperBound) const
{
    OutLowerBound = GeneLowerBound;
    OutUpperBound = GeneUpperBound;
}

void APopulation::SetGeneBounds(float NewLowerBound, float NewUpperBound)
{
    GeneLowerBound = NewLowerBound;
    GeneUpperBound = NewUpperBound;
}

TArray<AChromosome*>& APopulation::GetPopulation()
{
    return Chromosomes;
}

void APopulation::InitializePopulation()
{
    for (int32 i = 0; i < PopulationSize; ++i)
    {
        AChromosome* NewChromosome = GetWorld()->SpawnActor<AChromosome>(ChromosomeClass);
        NewChromosome->InitializeChromosome(ChromosomeLength, GeneLowerBound, GeneUpperBound);
        Chromosomes.Add(NewChromosome);
    }
}

void APopulation::AddChromosome(AChromosome* NewChromosome)
{
    Chromosomes.Add(NewChromosome);
}
