#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FLevelGeneticData.h"
#include "TotalWaveGeneticData.h"
#include "GenesData.generated.h"

USTRUCT(BlueprintType)
struct FGenesData
{
    GENERATED_BODY()

        //关卡序号
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenesDatae")
        int32 LevelIndex;

        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenesData")
        float levelPower;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenesData", Meta = (DisplayName = "LevelPowerFactor", ToolTip = "GeneticAlgorithmManagerData Parameter LevelBasepowerFactor*（currentlevelindex-1=*LevelPowerFactor）"))
        float LevelPowerFactor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenesData")
        float LevelDifficultyFactor;

    //关卡基因数据
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenesData")
		FLevelGeneticData LevelGeneticData;

    //关卡总波数基因数据
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenesData")
		FTotalWaveGeneticData TotalWaveGeneticData;
};