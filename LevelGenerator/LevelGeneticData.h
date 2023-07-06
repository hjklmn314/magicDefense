#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelGenerator/MDElementType.h"
#include "MDObstacleType.h"
#include "MDMoveType.h"
#include "LevelGeneticData.generated.h"

USTRUCT(BlueprintType)
struct FGridTerrainAttributes
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Terrain Attributes", Meta = (DisplayName = "TerrainActor", ToolTip = "A grid of Terrain block as an Actor"))
     AActor* TerrainActor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Terrain Attributes", Meta = (DisplayName = "TerrainLevel", ToolTip = "different Terrain Level has difference ObstacleSpawnWeight list "))
        int32 TerrainLevel;

        // Ԫ������
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Terrain Attributes", Meta = (DisplayName = "ElementType", ToolTip = "Terrain's ElementType Enum"))
        EMDElementType ElementType;

};

USTRUCT(BlueprintType)
struct FObstacleGeneticData
{
    GENERATED_BODY()

        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ObstacleGeneticData")
        EMDObstacleType ObstacleType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ObstacleGeneticData")
        FVector Location;
};


USTRUCT(BlueprintType)
struct FLevelGeneticData
{
    GENERATED_BODY()

    // ���ӵ���Ч������
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Gene")
        TArray<FGridTerrainAttributes> GridTerrainAttributes;

    // �ؿ��ϰ�������
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Gene")
        int32 ObstacleAndAmounts;

    // �ϰ���λ��
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Gene")
        TArray<FVector2D> ObstacleLocations;

    //�ϰ����б�
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Gene")
		TArray<AActor*> ObstacleList;

    //�ϰ�����ս����
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Gene")
		float ObstacleTotalPower;

};