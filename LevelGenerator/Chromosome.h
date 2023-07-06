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

    // 蓝图中初始化默认值 Initialize
    UFUNCTION(BlueprintImplementableEvent)
        void Initialize();
    /*    Genes.Empty();
    Fitness = 0;
    PassTime = 0;
    AvgPower = 0;
    Top25Power = 0;*/

    // 获取基因
    UFUNCTION(BlueprintCallable)
        TArray<float>& GetGenes();

    // 设置基因
    UFUNCTION(BlueprintCallable)
        void SetGenes(FGenesData inGenes);

    // 获取适应度
    UFUNCTION(BlueprintCallable)
        float GetFitness();

    // 设置适应度
    UFUNCTION(BlueprintCallable)
        void SetFitness(float InFitness);

    // 获取通关时间
    UFUNCTION(BlueprintCallable)
        float GetPassTime();

    // 设置通关时间
    UFUNCTION(BlueprintCallable)
        void SetPassTime(float InPassTime);

    // 获取当前关卡平均怪物强度
    UFUNCTION(BlueprintCallable)
        float GetMonsterAvgPower();

    // 设置当前关卡平均怪物强度
    UFUNCTION(BlueprintCallable)
        void SetMonsterAvgPower(float InMonsterAvgPower);

    // 获取难度系数
    UFUNCTION(BlueprintCallable)
        float GetDifficultyFactor();

    // 设置难度系数
    UFUNCTION(BlueprintCallable)
        void SetDifficultyFactor(float InDifficultyFactor);

    // 染色体的基因(离散变量),长度由配置表确定
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FGenesData Genes;

    // 染色体适应度
    UPROPERTY(BlueprintReadWrite)
        float Fitness;

    // 通关时间
    UPROPERTY(BlueprintReadWrite)
        float PassTime;

    // 当前关卡平均怪物强度
    UPROPERTY(BlueprintReadWrite)
        float MonsterAvgPower;

    //难度系数
    UPROPERTY(BlueprintReadWrite)
        float DifficultyFactor;

    UFUNCTION(BlueprintCallable)
        AChromosome* Clone() const;

    void CalculateFitness(int LastFailures, int BaseFailures, float MaxFailures, float InDifficultyFactor, float TotalTime, float AvgPower, float Top25CardPower);

};
