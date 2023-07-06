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

    // Ԫ�ػ���Ч��
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Terrain Attributes", Meta = (DisplayName = "ElementInteractionEffect", ToolTip = "Terrain's Element Interaction Effect Skill Actor refrence"))
        AActor* ElementInteractionEffect;

    // ���ƶ���
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Terrain Attributes", Meta = (DisplayName = "MoveType", ToolTip = "a MoveType enum,Monster can be pass the Terrain"))
        EMDMoveType MoveType;

    // �Ƿ�������ϰ���
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Terrain Attributes", Meta = (DisplayName = "bCanSpawnObstacle", ToolTip = "is The Terrain should be spawn an Obstacle,then spawn an ObstacleType's Obstacle from  ObstacleSpawnWeight which has been choosen"))
        bool bCanSpawnObstacle;

    // ֧���ϰ�������
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Terrain Attributes", Meta = (DisplayName = "ObstacleType", ToolTip = "Terrain only spawn the ObstacleType's Obstacle"))
        EMDObstacleType ObstacleType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Terrain Attributes", Meta = (DisplayName = "ObstacleSpawnWeight", ToolTip = "each element is a obstacleType's Obstacle and the obstacle spawn rate"))
        TMap<AActor*, float> ObstacleSpawnWeight;
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