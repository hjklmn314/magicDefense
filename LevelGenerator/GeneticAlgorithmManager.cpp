#include "GeneticAlgorithmManager.h"
#include "Math/UnrealMathUtility.h"
#include "Misc/OutputDeviceRedirector.h"

DECLARE_LOG_CATEGORY_EXTERN(LogVariable, Log, All);
DEFINE_LOG_CATEGORY(LogVariable);

// Sets default values
AGeneticAlgorithmManager::AGeneticAlgorithmManager()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    // Add this line to set the default class for PopulationClass
    PopulationClass = APopulation::StaticClass();
}
// Called when the game starts or when spawned
void AGeneticAlgorithmManager::BeginPlay()
{
    Super::BeginPlay();
    // Load parameters from the GeneticAlgorithmManagerData
    LoadParameters();
    // Check if it's a new game or if it should load the state from GeneticAlgorithmSaveGame
    UGeneticAlgorithmSaveGame* SaveGameInstance = Cast<UGeneticAlgorithmSaveGame>(UGameplayStatics::CreateSaveGameObject(UGeneticAlgorithmSaveGame::StaticClass()));
    if (UGameplayStatics::DoesSaveGameExist(SaveGameInstance->SaveSlotName, SaveGameInstance->UserIndex))
    {
        LoadStateFromSaveGame();
    }
    else
    {
        InitializeNewGame();
    }
}
// Called every frame
void AGeneticAlgorithmManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Evolve();
    CheckTermination();
}

void AGeneticAlgorithmManager::LoadParameters()
{
    UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::LoadParameters!START"));
    UGeneticAlgorithmManagerData* DataAsset = Cast<UGeneticAlgorithmManagerData>(StaticLoadObject(UGeneticAlgorithmManagerData::StaticClass(), nullptr, TEXT("/Game/GeneticAlgorithm/Data/DA_GeneticAlgorithmManagerData")));
    if (DataAsset)
    {
        ChromosomeLength = DataAsset->ChromosomeLength;
        GeneLowerBound = DataAsset->GeneLowerBound;
        GeneUpperBound = DataAsset->GeneUpperBound;
        MaxPopulationSize = DataAsset->MaxPopulationSize;
        BaseGenerations = DataAsset->BaseGenerations;
        BaseTime = DataAsset->BaseTime;
        TerminationFitnessThreshold = DataAsset->TerminationFitnessThreshold;
        TerminationChangeThreshold = DataAsset->TerminationChangeThreshold;
        MaxStallGenerations = DataAsset->MaxStallGenerations;
        MaxFailures = DataAsset->MaxFailures;
        BaseFailures = DataAsset->BaseFailures;
    }
    UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::LoadParameters,Compeleted!!"));
}


float AGeneticAlgorithmManager::GetTotalTime()
{
    return TotalTime;
}
void AGeneticAlgorithmManager::SetTotalTime(float InTotalTime)
{
    TotalTime = InTotalTime;
}


float AGeneticAlgorithmManager::GetAvgPower()
{
        return AvgPower;
}

void AGeneticAlgorithmManager::SetAvgPower(float InAvgPower)
{
	AvgPower = InAvgPower;
}


float AGeneticAlgorithmManager::GetTop25CardPower()
{
    return Top25Power;
}

void AGeneticAlgorithmManager::SetTop25CardPower(float InTop25Power)
{
	Top25Power = InTop25Power;
}

// Function to initialize a new game
void AGeneticAlgorithmManager::InitializeNewGame()
{
    UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::InitializeNewGame!"))
    Population.Reset(MaxPopulationSize);  // Set population size to MaxPopulationSize
    UE_LOG(LogVariable, Log, TEXT("MaxPopulationSize: %d"), MaxPopulationSize);
    //UE_LOG(LogTemp, Display, TEXT("Current MaxPopulationSize: %s"), MaxPopulationSize);
    for (int32 i = 0; i < MaxPopulationSize; i++)
    {
        AChromosome* NewChromosome = GetWorld()->SpawnActor<AChromosome>();
        NewChromosome->Initialize();
        Population.Add(NewChromosome);
    }
    StartTime = GetWorld()->GetTimeSeconds();
    DifficultyFactor = 1.0f; // Set default DifficultyFactor
    LastFailures = 0; // Set default LastFailures
    LastBestFitness = 0.0f;
    NonImprovingGens = 0;
    bTerminate = false;
   
    UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::InitializeNewGame,Compeleted!!"));
}

// Function to load state from GeneticAlgorithmSaveGame
void AGeneticAlgorithmManager::LoadStateFromSaveGame()
{
    UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::LoadStateFromSaveGame!"));
    UGeneticAlgorithmSaveGame* SaveGameInstance = Cast<UGeneticAlgorithmSaveGame>(UGameplayStatics::CreateSaveGameObject(UGeneticAlgorithmSaveGame::StaticClass()));
    if (SaveGameInstance)
    {
        MaxPopulationSize = SaveGameInstance->MaxPopulationSize;
        UE_LOG(LogVariable, Log, TEXT("MaxPopulationSize: %d"), MaxPopulationSize);
        Population.Reset(MaxPopulationSize);  // Set population size to MaxPopulationSize
        
        for (int32 i = 0; i < MaxPopulationSize; i++)
        {
            AChromosome* NewChromosome = GetWorld()->SpawnActor<AChromosome>();
            NewChromosome->Initialize();
            Population.Add(NewChromosome);
        }
        StartTime = SaveGameInstance->StartTime;
        DifficultyFactor = SaveGameInstance->DifficultyFactor;
        LastFailures = SaveGameInstance->LastFailures;
        LastBestFitness = SaveGameInstance->LastBestFitness;
        NonImprovingGens = SaveGameInstance->NonImprovingGens;
        bTerminate = SaveGameInstance->bTerminate;

        // Evaluate fitness for the loaded population
        EvaluateFitness(Population);
        UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::LoadStateFromSaveGame,Compeleted!!"));
    }
}

void AGeneticAlgorithmManager::Evolve()
{
    UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::Evolve,START!"));
    Generation++;
    UE_LOG(LogVariable, Log, TEXT("��ǰ����: %d"), Generation);
    TArray<AChromosome*> Parents = SelectParents();  // ѡ�񸸴�
    TArray<AChromosome*, FDefaultAllocator> LocalChildren= Crossover(Parents); // ��������Ӵ�
    TArray<AChromosome*> Mutants = MDMutate(LocalChildren);   // ����
    EvaluateFitness(Mutants);                          // ������Ӧ��
    ReplacePopulation(Mutants);                        // �滻��Ⱥ
}

bool AGeneticAlgorithmManager::CheckTermination()
{

  float  MaxGenerations = BaseGenerations * (1 + DifficultyFactor);
  float  MaxRunningTime = BaseTime * (1 + DifficultyFactor);

    // 1. Reach max generations
    if (Generation >= MaxGenerations)
        bTerminate = true;

    // 4. Resource exhaustion 
    float CurrentTime = GetWorld()->GetTimeSeconds();
    if (CurrentTime - StartTime >= MaxRunningTime)
        bTerminate = true;

    AChromosome* BestChromosome = FindBestChromosome();
    float CurrentBestFitness = BestChromosome->GetFitness();
    if (CurrentBestFitness >= TerminationFitnessThreshold)
        bTerminate = true;

    if (FMath::Abs(CurrentBestFitness - LastBestFitness) <= TerminationChangeThreshold)
        NonImprovingGens++;
    else
        NonImprovingGens = 0;

    if (NonImprovingGens >= MaxStallGenerations)
        bTerminate = true;

    LastBestFitness = CurrentBestFitness;

    if (bTerminate)
    {
        UE_LOG(LogTemp, Warning, TEXT("Termination condition reached!"));
        SaveStateToSaveGame();
    }
    return bTerminate;
}

void AGeneticAlgorithmManager::SaveStateToSaveGame()
{
    UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::SaveStateToSaveGame,Saving!"));
    UGeneticAlgorithmSaveGame* SaveGameInstance = Cast<UGeneticAlgorithmSaveGame>(UGameplayStatics::CreateSaveGameObject(UGeneticAlgorithmSaveGame::StaticClass()));
    if (SaveGameInstance)
    {
        SaveGameInstance->MaxPopulationSize = MaxPopulationSize;
        SaveGameInstance->StartTime = StartTime;
        SaveGameInstance->DifficultyFactor = DifficultyFactor;
        SaveGameInstance->LastFailures = LastFailures;
        SaveGameInstance->LastBestFitness = LastBestFitness;
        SaveGameInstance->NonImprovingGens = NonImprovingGens;
        SaveGameInstance->bTerminate = bTerminate;

        UGameplayStatics::SaveGameToSlot(SaveGameInstance, SaveGameInstance->SaveSlotName, SaveGameInstance->UserIndex);
    }
}

TArray<AChromosome*> AGeneticAlgorithmManager::SelectParents()
{
    // ��������ѡ�񷽷��ĸ���
    if (LastFailures > 0 && MaxFailures > 0)
    {
        float RouletteProb = 0.8f - 0.3f * (LastFailures / MaxFailures);
    }
    float RouletteProb = 0.8f ;
    float TournamentProb = 0.2f + 0.3f * DifficultyFactor;


    // ���ѡ��ʹ������ѡ�񷽷�
    float Selector = FMath::FRandRange(0.0f, 1.0f);

    TArray<AChromosome*> Parents;
    if (Selector < RouletteProb) {
        // ���̶�ѡ��
        UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::SelectParents,���̶�ѡ��!"));
        TArray<float> RouletteWheel;
        float TotalFitness = 0;
        for (auto Chromosome : Population) {
            TotalFitness += Chromosome->GetFitness();
        }
        for (auto Chromosome : Population) {
            RouletteWheel.Add(Chromosome->GetFitness() / TotalFitness);
        }
        // ���ѡ����������
        AChromosome* LocalParent1 = RouletteWheelSelection(RouletteWheel);
        AChromosome* LocalParent2 = RouletteWheelSelection(RouletteWheel);
        Parents.Add(LocalParent1);
        Parents.Add(LocalParent2);
    }
    else {
        // ������ѡ��
        UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::SelectParents,������ѡ��!"));
        TArray<AChromosome*> Candidates;
        // ����Ⱥ�����ѡ��4����ѡ����
        for (int i = 0; i < 4; i++) {
            Candidates.Add(Population[FMath::RandRange(0, Population.Num() - 1)]);
        }
        // ѡ���������Ÿ�����Ϊ����
        AChromosome* LocalBest1 = Candidates[0];
        AChromosome* LocalBest2 = Candidates[1];
        for (auto Chromosome : Candidates) {
            if (Chromosome->GetFitness() > LocalBest1->GetFitness())
                LocalBest1 = Chromosome;
            else if (Chromosome->GetFitness() > LocalBest2->GetFitness())
                LocalBest2 = Chromosome;
        }
        Parents.Add(LocalBest1);
        Parents.Add(LocalBest2);
    }
    UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::SelectParents::Compeleted!"));
    return Parents;
}

AChromosome* AGeneticAlgorithmManager::RouletteWheelSelection(TArray<float>& RouletteWheel)
{
    float Selector = FMath::FRandRange(0.0f, 1.0f);
    float CumSum = 0.0f;
    for (int i = 0; i < RouletteWheel.Num(); i++) {
        CumSum += RouletteWheel[i];
        if (Selector < CumSum) {
            return Population[i];
        }
    }
    return Population.Last();
}



// ��������Ӵ�(���㡢�������Ƚ���)
TArray<AChromosome*> AGeneticAlgorithmManager::Crossover(TArray<AChromosome*> Parents)
{
   TArray<AChromosome*, FDefaultAllocator> LocalChildren;
    // �������ֽ�������ĸ���
    float SinglePointProb = 0.3f - 0.2f * (LastFailures / MaxFailures);
    float TwoPointProb = 0.5f + 0.3f * DifficultyFactor;
    float UniformProb = 0.2f + 0.1f * DifficultyFactor;

    // ���ѡ��ʹ�����ֽ������
    float Selector = FMath::FRandRange(0.0f, 1.0f);

    if (Selector < SinglePointProb) {
        // ���㽻��
        UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::Crossover,SinglePointProb!"));
        int CrossoverPoint = FMath::RandRange(0, ChromosomeLength - 1);
        for (int i = 0; i < Parents.Num() / 2; i++) {
            AChromosome* LocalChild1 = Parents[i * 2]->Clone();
            AChromosome* LocalChild2 = Parents[i * 2 + 1]->Clone();
            LocalChild1->Genes = Parents[i * 2]->Genes;
            LocalChild2->Genes = Parents[i * 2 + 1]->Genes;
            LocalChild1->Genes.RemoveAt(CrossoverPoint + 1, ChromosomeLength - CrossoverPoint - 1);
            LocalChild1->Genes.Append(GetSubArray(Parents[i * 2 + 1]->Genes, CrossoverPoint + 1, ChromosomeLength - CrossoverPoint - 1));
            LocalChild2->Genes.RemoveAt(CrossoverPoint + 1, ChromosomeLength - CrossoverPoint - 1);
            LocalChild2->Genes.Append(GetSubArray(Parents[i * 2]->Genes, CrossoverPoint + 1, ChromosomeLength - CrossoverPoint - 1));
            LocalChildren.Add(LocalChild1);
            LocalChildren.Add(LocalChild2);
        }
    }
    else if (Selector < SinglePointProb + TwoPointProb) {
        // ���㽻��
        UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::Crossover, TwoPointProb!"));
        int CrossoverPoint1 = FMath::RandRange(0, ChromosomeLength - 1);
        int CrossoverPoint2 = FMath::RandRange(CrossoverPoint1, ChromosomeLength - 1);
        for (int i = 0; i < Parents.Num() / 2; i++) {
            AChromosome* LocalChild1 = Parents[i * 2]->Clone();
            AChromosome* LocalChild2 = Parents[i * 2 + 1]->Clone();
            LocalChild1->Genes = Parents[i * 2]->Genes;
            LocalChild2->Genes = Parents[i * 2 + 1]->Genes;
            LocalChild1->Genes.RemoveAt(CrossoverPoint1, CrossoverPoint2 - CrossoverPoint1);
            LocalChild1->Genes.Insert(GetSubArray(Parents[i * 2 + 1]->Genes, CrossoverPoint1, CrossoverPoint2 - CrossoverPoint1), CrossoverPoint1);
            LocalChild2->Genes.RemoveAt(CrossoverPoint1, CrossoverPoint2 - CrossoverPoint1);
            LocalChild2->Genes.Insert(GetSubArray(Parents[i * 2]->Genes, CrossoverPoint1, CrossoverPoint2 - CrossoverPoint1), CrossoverPoint1);
            LocalChildren.Add(LocalChild1);
            LocalChildren.Add(LocalChild2);
        }
    }
    else {
        // ���Ƚ���
        UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::Crossover,AvgProb!"));
        int NumGenes = FMath::RandRange(1, ChromosomeLength / 2);
        for (int i = 0; i < Parents.Num() / 2; i++) {
            AChromosome* LocalChild1 = Parents[i * 2]->Clone();
            AChromosome* LocalChild2 = Parents[i * 2 + 1]->Clone();
            LocalChild1->Genes = Parents[i * 2]->Genes;
            LocalChild2->Genes = Parents[i * 2 + 1]->Genes;
            for (int j = 0; j < NumGenes; j++) {
                int GeneIndex = FMath::RandRange(0, ChromosomeLength - 1);
                Swap(LocalChild1->Genes[GeneIndex], Parents[i * 2 + 1]->Genes[GeneIndex]);
                Swap(LocalChild2->Genes[GeneIndex], Parents[i * 2]->Genes[GeneIndex]);
            }
            LocalChildren.Add(LocalChild1);
            LocalChildren.Add(LocalChild2);
        }
    }
    UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::Crossover,Compeleted!"));
    return LocalChildren;
}

TArray<float> AGeneticAlgorithmManager::GetSubArray(const TArray<float>& Array, int StartIndex, int Length)
{
    TArray<float> SubArray;
    if (StartIndex >= 0 && Length > 0 && StartIndex + Length <= Array.Num())
    {
        for (int i = StartIndex; i < StartIndex + Length; ++i)
        {
            SubArray.Add(Array[i]);
        }
    }
    return SubArray;
}



// ����
TArray<AChromosome*> AGeneticAlgorithmManager::MDMutate(TArray<AChromosome*> ChildrenChromosome)
{
    UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::MDMutate,start!"));
    TArray<AChromosome*> Mutants;
    // ����ʧ�ܴ�����������ʵ�������,��Χ0-0.3
    float FailureRateFactor = 0.3f * (1 - (LastFailures - BaseFailures) / MaxFailures);

    // �����Ѷ�ϵ�����������,��Χ0.05-0.3
    float BaseRate = 0.05 + 0.25 * DifficultyFactor;

    // �������ձ�����
    MutationRate = BaseRate + FailureRateFactor;
    UE_LOG(LogVariable, Log, TEXT("���ձ�����: %f"), MutationRate);
    for (auto Chromosome : ChildrenChromosome) {
        // �Ƿ����
        if (FMath::FRandRange(0.0f, 1.0f) < MutationRate) {
            int GeneIndex = FMath::RandRange(0, ChromosomeLength - 1);
            UE_LOG(LogVariable, Log, TEXT("��ǰ����index: %d"), GeneIndex);
            // �������һ��������� 
            float MutantGene = FMath::FRandRange(GeneLowerBound, GeneUpperBound);
            UE_LOG(LogVariable, Log, TEXT("������� index: %d"), MutantGene);
            Chromosome->Genes[GeneIndex] = MutantGene;
        }
        Mutants.Add(Chromosome);
        UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::MDMutate,Compeleted!"));
    }
    return Mutants;
}

void AGeneticAlgorithmManager::EvaluateFitness(TArray<AChromosome*>& InPopulation)
{
    UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::EvaluateFitness,START!"));
    float InDifficultyFactor = DifficultyFactor;
    UE_LOG(LogVariable, Log, TEXT("DifficultyFactor: %f"), InDifficultyFactor);
    for (auto Chromosome : InPopulation) {
        // ������Ӧ��
        Chromosome->CalculateFitness(LastFailures, BaseFailures, MaxFailures, InDifficultyFactor, GetTotalTime(), GetAvgPower(), GetTop25CardPower());
    }
    UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::EvaluateFitness,Compeleted!"));
}


// �滻��Ⱥ
void AGeneticAlgorithmManager::ReplacePopulation(TArray<AChromosome*> Mutants)
{
    UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::ReplacePopulation,START!"));
    // Destroy previous chromosomes
    for (AChromosome* Chromosome : Population)
    {
        Chromosome->Destroy();
    }

    // Clear the current population array
    Population.Empty();

    // Add mutant chromosomes to the population
    for (AChromosome* Mutant : Mutants)
    {
        Population.Add(Mutant);
    }
    UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::ReplacePopulation,Compeleted!"));
}


AChromosome* AGeneticAlgorithmManager::FindBestChromosome()
{
    UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::FindBestChromosome,START!"));
    if (Population.Num() == 0)
    {
        return nullptr;
        UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::FindBestChromosome,Population IS Empty!"));
    }

    AChromosome* BestChromosome = Population[0];

    for (int i = 1; i < Population.Num(); i++)
    {
        if (Population[i]->GetFitness() > BestChromosome->GetFitness())
        {
            BestChromosome = Population[i];
        }
    }
    UE_LOG(LogTemp, Warning, TEXT("GeneticAlgorithmManager::ReplacePopulation,Compeleted!"));
    return BestChromosome;
}

void AGeneticAlgorithmManager::Swap(float& A, float& B)
{
    float Temp = A;
    A = B;
    B = Temp;
}


