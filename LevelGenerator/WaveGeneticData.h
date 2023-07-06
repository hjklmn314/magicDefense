#pragma once

#include "CoreMinimal.h"
#include "MDElementType.h"
#include "MonsterGeneticData.h"
#include "MonsterWaveData.h"
#include "WaveGeneticData.generated.h"

USTRUCT(BlueprintType)
struct FWaveGeneticData
{
    GENERATED_BODY()

        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
        int32 EnemyTypeCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
        TArray<EMDElementType> WaveElements;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
        int32 MonsterTotalCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
        float WaveTotalPower

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
        TArray<FMonsterWaveData> MonsterWaveData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave", Meta = (DisplayName = "HPFactor", ToolTip = "Monster lv.1 HP * HPFactor = Current Monster¡®s HP"))
        float HealthFactor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave", Meta = (DisplayName = "AttackFactor", ToolTip = "Monster lv.1 Attack * AttackFactor = Current Monster¡®s attack"))
        float AttackFactor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave", Meta = (DisplayName = "MoveSpeedFactor", ToolTip = "Monster lv.1 MoveSpeed * MoveSpeedFactor = Current Monster¡®s MoveSpeed,Clamp MoveSpeed to minMoveSpeed £¬currentMoveSpeed,maxMoveSpeed"))
        float MoveSpeedFactor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave", Meta = (DisplayName = "AttackSpeedFactor", ToolTip = "Monster lv.1 AttackSpeed * AttackSpeedFactor = Current Monster¡®s AttackSpeed,Clamp AttackSpeed to minAttackSpeed £¬currentattackSpeed,maxAttackSpeed"))
        float AttackSpeedFactor;



};