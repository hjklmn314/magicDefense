#pragma once
#include "CoreMinimal.h"
#include "Chromosome.h"
#include "Population.h"
#include "GeneticAlgorithmSaveGame.h"
#include "GeneticAlgorithmManagerData.h"
#include "Kismet/GameplayStatics.h"
#include "GeneticAlgorithmManager.generated.h"

UCLASS(Blueprintable)
class MAGICDEFENSE_API AGeneticAlgorithmManager : public AActor
{
    GENERATED_BODY()

public:
    AGeneticAlgorithmManager();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(BlueprintReadOnly)
        int LastFailures;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genetic Algorithm")
        int BaseFailures;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genetic Algorithm")
        float DifficultyFactor;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genetic Algorithm")
        int BaseGenerations;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genetic Algorithm")
        float BaseTime;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genetic Algorithm")
        float TerminationFitnessThreshold;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genetic Algorithm")
        int MaxStallGenerations;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genetic Algorithm")
        int MaxFailures;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genetic Algorithm")
        int NonImprovingGens;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
        int32 SelectionMethod;  // 0 = Roulette, 1 = Tournament

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
        int32 CrossoverMethod;  // 0 = Single Point, 1 = Two Point, 2 = Uniform

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
        int32 MaxPopulationSize;

    UFUNCTION(BlueprintCallable)
        void InitializeNewGame();

    UFUNCTION(BlueprintCallable)
        void LoadParameters();

    UFUNCTION(BlueprintCallable)
        void Evolve();

    UFUNCTION(BlueprintCallable)
        bool CheckTermination();

    UFUNCTION(BlueprintCallable)
        TArray<AChromosome*> SelectParents();

    UFUNCTION(BlueprintCallable)
        AChromosome* RouletteWheelSelection(TArray<float>& RouletteWheel);

    UFUNCTION(BlueprintCallable)
        TArray<AChromosome*> Crossover(TArray<AChromosome*> Parents);

    UFUNCTION(BlueprintCallable)
        TArray<AChromosome*> MDMutate(TArray<AChromosome*> ChildrenChromosome);

    UFUNCTION(BlueprintCallable)
        void EvaluateFitness(TArray<AChromosome*>& Population);

    UFUNCTION(BlueprintCallable)
        void ReplacePopulation(TArray<AChromosome*> Mutants);

    UFUNCTION(BlueprintCallable)
        AChromosome* FindBestChromosome();

    UFUNCTION(BlueprintCallable)
        void SaveStateToSaveGame();

    UFUNCTION(BlueprintCallable)
        void LoadStateFromSaveGame();
    // Add the missing declarations
    int ChromosomeLength;
    int GeneLowerBound;
    int GeneUpperBound;
    float TerminationChangeThreshold;

    UPROPERTY(BlueprintReadOnly)
        TSubclassOf<APopulation> PopulationClass;

    UPROPERTY(BlueprintReadOnly)
        TArray<AChromosome*> Population;

    UPROPERTY(BlueprintReadOnly)
        int32 Generation;

    UPROPERTY(BlueprintReadOnly)
        float MutationRate;

    UPROPERTY(BlueprintReadOnly)
        bool bTerminate;

    AChromosome* Parent1;
    AChromosome* Parent2;
    AChromosome* Best1;
    AChromosome* Best2;
    AChromosome* Child1;
    AChromosome* Child2;
    // 算法开始执行时间
    float StartTime;

    float TotalTime;
    float AvgPower;
    float Top25Power;
    // 上一次最优个体的适应度 
    float LastBestFitness;

    UFUNCTION(BlueprintCallable)
        void SetTotalTime(float InTotalTime);

    UFUNCTION(BlueprintCallable)
        void SetAvgPower(float InAvgPower);

    UFUNCTION(BlueprintCallable)
        void SetTop25CardPower(float InTop25Power);

    UFUNCTION(BlueprintCallable)
        void Swap(float& A, float& B);

    float GetTotalTime();
    float GetAvgPower();
    float GetTop25CardPower();

    TArray<float, FDefaultAllocator> GetSubArray(const TArray<float, FDefaultAllocator>& SourceArray, int32 StartIndex, int32 Length);
};

