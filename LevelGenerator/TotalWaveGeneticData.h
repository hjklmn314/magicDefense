#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "WaveGeneticData.h"
#include "TotalWaveGeneticData.generated.h"

USTRUCT(BlueprintType)
struct FTotalWaveGeneticData
{
    GENERATED_BODY()

        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TotalWave")
        int32 TotalWaves;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TotalWave")
        TArray<int32> WaveElements;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TotalWave")
        TArray<float>  WavesInterval;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TotalWave")
        float TotalWavePower;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TotalWave")
        TArray<float> WavesDifficulty;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TotalWave")
        TArray<float> WavesPower;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TotalWave")
        bool bIsBossLevel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TotalWave")
        TArray<FWaveGeneticData> WaveList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TotalWave")
        FWaveGeneticData BossWaveData;


};