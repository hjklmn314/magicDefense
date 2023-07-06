#include "Chromosome.h"
#include "Misc/OutputDeviceRedirector.h"

DECLARE_LOG_CATEGORY_EXTERN(LogChromosome, Log, All);
DEFINE_LOG_CATEGORY(LogChromosome);

// Sets default values
AChromosome::AChromosome()
{
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AChromosome::BeginPlay()
{
    Super::BeginPlay();
    Initialize();
}

// Called every frame
void AChromosome::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// 获取基因
TArray<float>& AChromosome::GetGenes()
{
    return Genes;
}

// 设置基因
void AChromosome::SetGenes(FGenesData inGenes);
{
    UE_LOG(LogTemp, Warning, TEXT("AChromosome::SetGenes,start!"));
    Genes = inGenes;
}

// 获取适应度
float AChromosome::GetFitness()
{
    return Fitness;
}

// 设置适应度  
void AChromosome::SetFitness(float InFitness)
{
    Fitness = InFitness;
}

// 获取通关时间 
float AChromosome::GetPassTime()
{
    return PassTime;
}

// 设置通关时间
void  AChromosome::SetPassTime(float InPassTime)
{
    PassTime = InPassTime;
}

// 获取平均卡牌强度
float AChromosome::GetMonsterAvgPower()
{
    return MonsterAvgPower;
}

// 设置当前关卡平均怪物强度
void AChromosome::SetMonsterAvgPower(float InMonsterAvgPower)
{
    MonsterAvgPower = InMonsterAvgPower;
}


// 获得难度系数
float AChromosome::GetDifficultyFactor()
{
    return DifficultyFactor;
}

// 设置难度系数
void AChromosome::SetDifficultyFactor(float InDifficultyFactor)
{
    DifficultyFactor = InDifficultyFactor;
}

AChromosome* AChromosome::Clone() const
{

    UE_LOG(LogTemp, Warning, TEXT("AChromosome::Clone,start!"));
    AChromosome* NewChromosome = NewObject<AChromosome>();
    NewChromosome->Genes = Genes;
    NewChromosome->Fitness = Fitness;
    NewChromosome->PassTime = PassTime;
    NewChromosome->MonsterAvgPower = MonsterAvgPower;
    NewChromosome->DifficultyFactor = DifficultyFactor;
    UE_LOG(LogTemp, Warning, TEXT("AChromosome::Clone completed!"));
    return NewChromosome;
}

void AChromosome::CalculateFitness(int LastFailures, int BaseFailures, float MaxFailures, float InDifficultyFactor, float TotalTime, float AvgPower, float Top25CardPower)
{
    UE_LOG(LogTemp, Warning, TEXT("AChromosome::CalculateFitness,start!"));
    float LocalFitness = 0;

    // 通关时间比,权重0.35
    float PassTimeRatio = GetPassTime() / TotalTime;
    LocalFitness += 0.35 * PassTimeRatio;

    // 失败次数,权重0.3
    float FailureRatio = (LastFailures - BaseFailures) / MaxFailures;
    LocalFitness -= 0.3 * FailureRatio;

    // 平均强度比,权重0.25
    float AvgPowerRatio = GetMonsterAvgPower() / AvgPower;
    LocalFitness += 0.25 * AvgPowerRatio;

    // 前25名卡牌平均强度比,权重0.1
    float Top25PowerRatio = GetMonsterAvgPower() / Top25CardPower;
    LocalFitness += 0.1 * Top25PowerRatio;
    UE_LOG(LogChromosome, Log, TEXT("CalculateFitness: %f"), LocalFitness);
    // 设置适应度
    UE_LOG(LogTemp, Warning, TEXT("AChromosome::CalculateFitness completed!"));
    SetFitness(LocalFitness);
}
