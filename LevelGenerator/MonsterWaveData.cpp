#pragma once

#include "CoreMinimal.h"
#include "MDElementType.h"
#include "MonsterGeneticData.h"
#include "MonsterWaveData.generated.h"

USTRUCT(BlueprintType)
struct FMonsterWaveData
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MonsterWaveWave")
    FMonsterGeneticData MonsterGeneticData; 

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MonsterWaveWave")
         int32 MonsterCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MonsterWaveWave")
        float StartSpawnTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MonsterWaveWave")
        float SpawnInterval;
};