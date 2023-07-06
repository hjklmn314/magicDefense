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

        //�ؿ����
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenesDatae")
        int32 LevelIndex;

        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenesData")
        float levelPower;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenesData", Meta = (DisplayName = "LevelPowerFactor", ToolTip = "GeneticAlgorithmManagerData Parameter LevelBasepowerFactor*��currentlevelindex-1=*LevelPowerFactor��"))
        float LevelPowerFactor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenesData")
        float LevelDifficultyFactor;

    //�ؿ���������
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenesData")
		FLevelGeneticData LevelGeneticData;

    //�ؿ��ܲ�����������
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenesData")
		FTotalWaveGeneticData TotalWaveGeneticData;
};