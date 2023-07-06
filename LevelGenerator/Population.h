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

    // ��ȡ��Ⱥ��С
    UFUNCTION(BlueprintCallable)
        int32 GetPopulationSize() const;

    // ������Ⱥ��С
    UFUNCTION(BlueprintCallable)
        void SetPopulationSize(int32 NewSize);

    // ��ȡȾɫ�峤��  
    UFUNCTION(BlueprintCallable)
        int32 GetChromosomeLength() const;

    // ����Ⱦɫ�峤��
    UFUNCTION(BlueprintCallable)
        void SetChromosomeLength(int32 NewLength);

    // ��ȡ����������  
    UFUNCTION(BlueprintCallable)
        void GetGeneBounds(float& OutLowerBound, float& OutUpperBound) const;

    // ���û���������
    UFUNCTION(BlueprintCallable)
        void SetGeneBounds(float NewLowerBound, float NewUpperBound);

    // ��ȡ��Ⱥ
    UFUNCTION(BlueprintCallable)
        TArray<AChromosome*>& GetPopulation();

    // ��ʼ����Ⱥ
    UFUNCTION(BlueprintCallable)
        void InitializePopulation();

    // ���Ⱦɫ�嵽��Ⱥ
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
