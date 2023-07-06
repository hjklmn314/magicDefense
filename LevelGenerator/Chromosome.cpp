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

// ��ȡ����
TArray<float>& AChromosome::GetGenes()
{
    return Genes;
}

// ���û���
void AChromosome::SetGenes(FGenesData inGenes);
{
    UE_LOG(LogTemp, Warning, TEXT("AChromosome::SetGenes,start!"));
    Genes = inGenes;
}

// ��ȡ��Ӧ��
float AChromosome::GetFitness()
{
    return Fitness;
}

// ������Ӧ��  
void AChromosome::SetFitness(float InFitness)
{
    Fitness = InFitness;
}

// ��ȡͨ��ʱ�� 
float AChromosome::GetPassTime()
{
    return PassTime;
}

// ����ͨ��ʱ��
void  AChromosome::SetPassTime(float InPassTime)
{
    PassTime = InPassTime;
}

// ��ȡƽ������ǿ��
float AChromosome::GetMonsterAvgPower()
{
    return MonsterAvgPower;
}

// ���õ�ǰ�ؿ�ƽ������ǿ��
void AChromosome::SetMonsterAvgPower(float InMonsterAvgPower)
{
    MonsterAvgPower = InMonsterAvgPower;
}


// ����Ѷ�ϵ��
float AChromosome::GetDifficultyFactor()
{
    return DifficultyFactor;
}

// �����Ѷ�ϵ��
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

    // ͨ��ʱ���,Ȩ��0.35
    float PassTimeRatio = GetPassTime() / TotalTime;
    LocalFitness += 0.35 * PassTimeRatio;

    // ʧ�ܴ���,Ȩ��0.3
    float FailureRatio = (LastFailures - BaseFailures) / MaxFailures;
    LocalFitness -= 0.3 * FailureRatio;

    // ƽ��ǿ�ȱ�,Ȩ��0.25
    float AvgPowerRatio = GetMonsterAvgPower() / AvgPower;
    LocalFitness += 0.25 * AvgPowerRatio;

    // ǰ25������ƽ��ǿ�ȱ�,Ȩ��0.1
    float Top25PowerRatio = GetMonsterAvgPower() / Top25CardPower;
    LocalFitness += 0.1 * Top25PowerRatio;
    UE_LOG(LogChromosome, Log, TEXT("CalculateFitness: %f"), LocalFitness);
    // ������Ӧ��
    UE_LOG(LogTemp, Warning, TEXT("AChromosome::CalculateFitness completed!"));
    SetFitness(LocalFitness);
}
