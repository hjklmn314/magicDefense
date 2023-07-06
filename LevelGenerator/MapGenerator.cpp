#include "MapGenerator.h"
#include "GeneticAlgorithm.h"

AMapGenerator::AMapGenerator()
{
    PrimaryActorTick.bCanEverTick = true;

    GeneticAlgorithm = CreateDefaultSubobject<UGeneticAlgorithm>(TEXT("GeneticAlgorithm"));
    if (!GeneticAlgorithm)
    {
        UE_LOG(LogTemp, Error, TEXT("Genetic Algorithm not initialized for MapGenerator"));
    }
}

void AMapGenerator::BeginPlay()
{
    Super::BeginPlay();

    GeneticAlgorithm->InitializePopulation();
    GenerateMap();
}

void AMapGenerator::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMapGenerator::GenerateMap()
{
    TArray<FLevelGeneticData> LevelGeneticDataArray = GeneticAlgorithm->GetBestChromosome();

    for (const FLevelGeneticData& LevelGeneticData : LevelGeneticDataArray)
    {
        GenerateTerrainEffects(LevelGeneticData);
        GenerateObstacles(LevelGeneticData);
    }
}

void AMapGenerator::GenerateTerrainEffects(const FLevelGeneticData& LevelGeneticData)
{
    int32 GridRows = 10;
    int32 GridColumns = 5;
    float CellWidth = 100.0f; // Set the width of each grid cell according to your requirements
    float CellHeight = 100.0f; // Set the height of each grid cell according to your requirements

    for (int32 i = 0; i < GridRows; ++i)
    {
        for (int32 j = 0; j < GridColumns; ++j)
        {
            // Determine the index in the TerrainAttributes array
            int32 Index = i * GridColumns + j;

            // Check if the index is within the bounds of the Terrain Attributes array
            if (Index < LevelGeneticData.TerrainAttributes.Num())
            {
                // Set terrain effect attributes for each grid cell based on LevelGeneticData
                FGridTerrainAttributes TerrainAttributes = LevelGeneticData.TerrainAttributes[Index];

                // Spawn a terrain actor subclass based on ElementType
                UClass *TerrainActorClass;
                FVector SpawnLocation = FVector(j * CellWidth, i * CellHeight, 0);
                FTransform SpawnTransform(FRotator::ZeroRotator, SpawnLocation);

                switch (TerrainAttributes.ElementType)
                {
                case EElementType::Fire:
                    TerrainActorClass = AFireTerrain::StaticClass();
                    break;
                case EElementType::Water:
                    TerrainActorClass = AWaterTerrain::StaticClass();
                    break;
                // Add other cases for each ElementType
                default:
                    TerrainActorClass = ADefaultTerrain::StaticClass();
                    break;
                }

                AActor* TerrainActor = GetWorld()->SpawnActor<AActor>(TerrainActorClass, SpawnTransform);

                // Set attributes like ElementType, Element Interaction Effect, Movable, etc.
                // Apply these attributes to the TerrainActor or modify the environment accordingly

                ATerrainBase* TerrainInstance = Cast<ATerrainBase>(TerrainActor);
                TerrainInstance->SetElementType(TerrainAttributes.ElementType);
                TerrainInstance->SetElementInteractionEffect(TerrainAttributes.ElementInteractionEffect);
                TerrainInstance->SetMovable(TerrainAttributes.bIsMovable);
                TerrainInstance->SetCanSpawnObstacle(TerrainAttributes.bCanSpawnObstacle);
                TerrainInstance->SetAllowedObstacleTypes(TerrainAttributes.AllowedObstacleTypes);

                // Perform additional steps to set up the terrain, e.g., configure materials, effects, etc.
                TerrainInstance->Initialize();
            }
        }
    }
}

void AMapGenerator::GenerateObstacles(const FLevelGeneticData& LevelGeneticData)
{
    for (const FObstacleGeneticData& ObstacleGeneticData : LevelGeneticData.ObstaclesData)
    {
        // Spawn obstacles based on ObstacleGeneticData int32 ObstacleRowIndex = ObstacleGeneticData.RowIndex; int32 ObstacleColIndex = ObstacleGeneticData.ColIndex; EMDObstacleType ObstacleType = ObstacleGeneticData.ObstacleType;

        if (ObstacleType != EMDObstacleType::None)
        {
            FVector SpawnLocation = GetSpawnLocation(ObstacleRowIndex, ObstacleColIndex);
            FRotator SpawnRotation = FRotator::ZeroRotator;
            FActorSpawnParameters SpawnParameters;

            UClass* ObstacleClass = GetObstacleClassByType(ObstacleType);
            AActor* SpawnedObstacle = GetWorld()->SpawnActor(ObstacleClass, &SpawnLocation, &SpawnRotation, SpawnParameters);

            if (SpawnedObstacle)
            {
                UE_LOG(LogTemp, Log, TEXT("Spawned Obstacle at Row: %d, Col: %d, Type: %d"), ObstacleRowIndex, ObstacleColIndex, static_cast<int32>(ObstacleType));
            }
        }
    }
}

FVector AMapGenerator::GetSpawnLocation(int32 RowIndex, int32 ColIndex)
{
    // Calculate the spawn location based on rowIndex, colIndex, grid size and offsets // Replace these values with the appropriate ones for your project float GridSize = 100.0f; float XOffset = -200.0f; float YOffset = -200.0f; float ZOffset = 0.0f;

    float X = XOffset + GridSize * RowIndex;
    float Y = YOffset + GridSize * ColIndex;
    float Z = ZOffset;

    return FVector(X, Y, Z);
}

 UClass* AMapGenerator::GetObstacleClassByType(EMDObstacleType ObstacleType)
{
        UClass* ObstacleClass = nullptr;

        // Determine the appropriate UClass based on the ObstacleType
        switch (ObstacleType)
        {
        case EMDObstacleType::WoodenObstacle:
            ObstacleClass = AWoodenObstacle::StaticClass();
            break;
        case EMDObstacleType::StoneObstacle:
            ObstacleClass = AStoneObstacle::StaticClass();
            break;
            // ... Other cases for each obstacle type
        default:
            break;
        }

        return ObstacleClass;
 }

 void AMapGenerator::GenerateObstacles(const FLevelGeneticData & LevelGeneticData)
 {
    for (const FObstacleGeneticData& ObstacleGeneticData : LevelGeneticData.ObstaclesData)
    {
       UClass* ObstacleClass = GetObstacleClassByType(ObstacleGeneticData.ObstacleType);
        if (ObstacleClass)
        {
            // Spawn the obstacle at the specified location
                FTransform SpawnTransform(FRotator::ZeroRotator, ObstacleGeneticData.Location);
                GetWorld()->SpawnActor<AActor>(ObstacleClass, SpawnTransform);
        }
     }
 }
 
void AMapGenerator::GenerateOuterArea()
{
    // 生成战场外围样式
    if (OuterAreaStyles.Num() > 0)
    {
        int32 RandomIndex = FMath::RandRange(0, OuterAreaStyles.Num() - 1);
        TSubclassOf<AActor> SelectedStyle = OuterAreaStyles[RandomIndex];

        FVector SpawnLocation = FVector::ZeroVector; // 设置适当的生成位置
        FRotator SpawnRotation = FRotator::ZeroRotator; // 设置适当的生成旋转
        GetWorld()->SpawnActor<AActor>(SelectedStyle, SpawnLocation, SpawnRotation);
    }
}
void AMapGenerator::GenerateEndPointArea()
{
    // Set end point area rows and columns
    const int32 EndPointAreaRows = 1;
    const int32 EndPointAreaColumns = 5;

    // Calculate start and middle location of end point area
    const FVector StartLocation = FVector(0, 0, 0); // Set start location based on actual needs
    const FVector MiddleLocation = StartLocation + FVector((EndPointAreaColumns / 2) * GridSize, 0, 0);

    // Traverse each grid of the end point area
    for (int32 Row = 0; Row < EndPointAreaRows; ++Row)
    {
        for (int32 Column = 0; Column < EndPointAreaColumns; ++Column)
        {
            // Calculate current grid location
            const FVector GridLocation = StartLocation + FVector(Row * GridSize, Column * GridSize, 0);

            // Spawn mage character at current grid location
            FActorSpawnParameters SpawnParams;
            SpawnParams.Owner = this;
            AMageCharacter* Mage = GetWorld()->SpawnActor<AMageCharacter>(MageCharacterClass, GridLocation, FRotator::ZeroRotator, SpawnParams);

            // Add mage character to end point area array
            EndPointArea.Add(Mage);

            // Set mage character as immovable if at the middle grid
            if (GridLocation == MiddleLocation)
            {
                Mage->SetCanMove(false);
            }
        }
    }
}

void AMapGenerator::GenerateSpawnPointArea()
{
    // 怪物出生点区域的行和列数
    const int32 SpawnAreaRows = 1;
    const int32 SpawnAreaCols = 5;

    // 遍历出生点区域的每个格子
    for (int32 Row = 0; Row < SpawnAreaRows; ++Row)
    {
        for (int32 Col = 0; Col < SpawnAreaCols; ++Col)
        {
            // 计算当前格子的世界坐标
            FVector SpawnLocation = FVector(Row * TileSize, Col * TileSize, 0);

            // 检查当前格子下方的战斗区域格子是否有障碍物
            int32 BattleAreaRow = Row + 1;
            int32 BattleAreaCol = Col;
            int32 BattleAreaIndex = BattleAreaRow * BattleAreaCols + BattleAreaCol;

            // 如果战斗区域格子没有障碍物，则在当前格子生成怪物出生点
            if (!ObstacleGrid[BattleAreaIndex])
            {
                // 在当前格子生成怪物出生点（例如，可以使用一个空的 StaticMeshActor 作为出生点）
                FActorSpawnParameters SpawnParams;
                SpawnParams.Owner = this;
                AActor* SpawnPoint = GetWorld()->SpawnActor<AActor>(SpawnPointClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams);

                // 将生成的出生点添加到一个数组中，以便在游戏逻辑中使用
                SpawnPoints.Add(SpawnPoint);
            }
        }
    }
}