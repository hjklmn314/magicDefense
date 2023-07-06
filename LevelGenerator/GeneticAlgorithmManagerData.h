#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GeneticAlgorithmManagerData.generated.h"

UCLASS(BlueprintType)
class MAGICDEFENSE_API UGeneticAlgorithmManagerData : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Genetic Algorithm", Meta = (ToolTip = "染色体长度，ChromosomeLength"))
        int32 ChromosomeLength;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Genetic Algorithm")
        float GeneLowerBound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Genetic Algorithm")
        float GeneUpperBound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Genetic Algorithm")
        int32 MaxPopulationSize;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Genetic Algorithm")
        int32 BaseGenerations;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Genetic Algorithm")
        float BaseTime;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Genetic Algorithm")
        float TerminationFitnessThreshold;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Genetic Algorithm")
        float TerminationChangeThreshold;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Genetic Algorithm")
        int32 MaxStallGenerations;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Genetic Algorithm", Meta = (ToolTip = "需要改变下一关卡难度系数的最大失败次数，limit change difficulty range for next level"))
        int32 MaxFailures;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Genetic Algorithm", Meta = (ToolTip = "需要改变下一关卡难度系数的基础失败次数，the min failures count to change difficulty for next level"))
        int32 BaseFailures;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Genetic Algorithm", Meta = (ToolTip = "第一关的关卡战力系数，影响怪物和障碍物相关属性， The LevelBasePowerFactor of first level calibrates specifications belonging to Monsters and Obstacle"))
        float LevelBasePowerFactor;

    // 固定格子数量（8行5列，49格子）
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genetic Algorithm", Meta = (ToolTip = "战场区域的列数，The number of Rows of grid cells in the battlefield area."))
        int32 GridRows = 8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genetic Algorithm", Meta = (ToolTip = "战场区域的行数，The number of Columns of grid cells in the battlefield area."))
        int32 GridColumns = 5;

    // 格子大小固定
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genetic Algorithm", Meta = (ToolTip = "格子的大小，The size of grid cell."))
        float GridSize = 100.0f;

};
