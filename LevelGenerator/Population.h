#pragma once

#include "CoreMinimal.h"
#include "Chromosome.h"
#include "GameFramework/Actor.h"
#include "Population.generated.h"

UCLASS()
class MAGICDEFENSE_API APopulation : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    APopulation();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // 获取种群大小
    UFUNCTION(BlueprintCallable)
        int32 GetPopulationSize() const;

    // 设置种群大小
    UFUNCTION(BlueprintCallable)
        void SetPopulationSize(int32 NewSize);

    // 获取染色体长度  
    UFUNCTION(BlueprintCallable)
        int32 GetChromosomeLength() const;

    // 设置染色体长度
    UFUNCTION(BlueprintCallable)
        void SetChromosomeLength(int32 NewLength);

    // 获取基因上下限  
    UFUNCTION(BlueprintCallable)
        void GetGeneBounds(float& OutLowerBound, float& OutUpperBound) const;

    // 设置基因上下限
    UFUNCTION(BlueprintCallable)
        void SetGeneBounds(float NewLowerBound, float NewUpperBound);

    // 获取种群
    UFUNCTION(BlueprintCallable)
        TArray<AChromosome*>& GetPopulation();

    // 初始化种群
    UFUNCTION(BlueprintCallable)
        void InitializePopulation();

    // 添加染色体到种群
    UFUNCTION(BlueprintCallable)
        void AddChromosome(AChromosome* NewChromosome);

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TSubclassOf<AChromosome> ChromosomeClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 PopulationSize;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 ChromosomeLength;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float GeneLowerBound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float GeneUpperBound;

    UPROPERTY(BlueprintReadOnly)
        TArray<AChromosome*> Chromosomes;
};
