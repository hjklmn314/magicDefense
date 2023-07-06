#include "CoreMinimal.h"
#include "LevelGeneticData.h"
#include "MDObstacleType.h"
#include "MDMoveType.h"
#include "GeneticData.generated.h"


USTRUCT(BlueprintType)
struct FGeneticData
{
    GENERATED_BODY()

        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genetic")
        FLevelGeneticData LevelData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genetic")
        FMonsterGeneticData MonsterData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genetic")
        FWaveGeneticData WaveData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genetic")
        float DifficultyFactor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genetic", Meta = (DisplayName = "LevelPowerFactor", ToolTip = "GeneticAlgorithmManagerData Parameter LevelBasepowerFactor*£¨currentlevelindex-1=*LevelPowerFactor£©"))
        float LevelPowerFactor;

};
