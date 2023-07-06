#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GeneticAlgorithmManagerData.generated.h"

UCLASS(BlueprintType)
class MAGICDEFENSE_API UGeneticAlgorithmManagerData : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Genetic Algorithm", Meta = (ToolTip = "Ⱦɫ�峤�ȣ�ChromosomeLength"))
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

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Genetic Algorithm", Meta = (ToolTip = "��Ҫ�ı���һ�ؿ��Ѷ�ϵ�������ʧ�ܴ�����limit change difficulty range for next level"))
        int32 MaxFailures;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Genetic Algorithm", Meta = (ToolTip = "��Ҫ�ı���һ�ؿ��Ѷ�ϵ���Ļ���ʧ�ܴ�����the min failures count to change difficulty for next level"))
        int32 BaseFailures;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Genetic Algorithm", Meta = (ToolTip = "��һ�صĹؿ�ս��ϵ����Ӱ�������ϰ���������ԣ� The LevelBasePowerFactor of first level calibrates specifications belonging to Monsters and Obstacle"))
        float LevelBasePowerFactor;

    // �̶�����������8��5�У�49���ӣ�
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genetic Algorithm", Meta = (ToolTip = "ս�������������The number of Rows of grid cells in the battlefield area."))
        int32 GridRows = 8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genetic Algorithm", Meta = (ToolTip = "ս�������������The number of Columns of grid cells in the battlefield area."))
        int32 GridColumns = 5;

    // ���Ӵ�С�̶�
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genetic Algorithm", Meta = (ToolTip = "���ӵĴ�С��The size of grid cell."))
        float GridSize = 100.0f;

};
