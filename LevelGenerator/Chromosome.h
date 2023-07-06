#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GenesData.h"
#include "Chromosome.generated.h"

UCLASS(Blueprintable)
class MAGICDEFENSE_API AChromosome : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AChromosome();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // ��ͼ�г�ʼ��Ĭ��ֵ Initialize
    UFUNCTION(BlueprintImplementableEvent)
        void Initialize();
    /*    Genes.Empty();
    Fitness = 0;
    PassTime = 0;
    AvgPower = 0;
    Top25Power = 0;*/

    // ��ȡ����
    UFUNCTION(BlueprintCallable)
        TArray<float>& GetGenes();

    // ���û���
    UFUNCTION(BlueprintCallable)
        void SetGenes(FGenesData inGenes);

    // ��ȡ��Ӧ��
    UFUNCTION(BlueprintCallable)
        float GetFitness();

    // ������Ӧ��
    UFUNCTION(BlueprintCallable)
        void SetFitness(float InFitness);

    // ��ȡͨ��ʱ��
    UFUNCTION(BlueprintCallable)
        float GetPassTime();

    // ����ͨ��ʱ��
    UFUNCTION(BlueprintCallable)
        void SetPassTime(float InPassTime);

    // ��ȡ��ǰ�ؿ�ƽ������ǿ��
    UFUNCTION(BlueprintCallable)
        float GetMonsterAvgPower();

    // ���õ�ǰ�ؿ�ƽ������ǿ��
    UFUNCTION(BlueprintCallable)
        void SetMonsterAvgPower(float InMonsterAvgPower);

    // ��ȡ�Ѷ�ϵ��
    UFUNCTION(BlueprintCallable)
        float GetDifficultyFactor();

    // �����Ѷ�ϵ��
    UFUNCTION(BlueprintCallable)
        void SetDifficultyFactor(float InDifficultyFactor);

    // Ⱦɫ��Ļ���(��ɢ����),���������ñ�ȷ��
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FGenesData Genes;

    // Ⱦɫ����Ӧ��
    UPROPERTY(BlueprintReadWrite)
        float Fitness;

    // ͨ��ʱ��
    UPROPERTY(BlueprintReadWrite)
        float PassTime;

    // ��ǰ�ؿ�ƽ������ǿ��
    UPROPERTY(BlueprintReadWrite)
        float MonsterAvgPower;

    //�Ѷ�ϵ��
    UPROPERTY(BlueprintReadWrite)
        float DifficultyFactor;

    UFUNCTION(BlueprintCallable)
        AChromosome* Clone() const;

    void CalculateFitness(int LastFailures, int BaseFailures, float MaxFailures, float InDifficultyFactor, float TotalTime, float AvgPower, float Top25CardPower);

};
