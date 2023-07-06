#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "MDMoveType.h"
#include "MDElementType.h"
#include "MonsterGeneticData.generated.h"

UENUM(BlueprintType)
enum class EMonsterType : uint8
{
	NormalMonster        UMETA(DisplayName = "NormalMonster", ToolTip = "��ͨ��"),
    AdvancedMonster      UMETA(DisplayName = "AdvancedMonster", ToolTip = "���׹�"),
    EliteMonster         UMETA(DisplayName = "EliteMonster", ToolTip = "��Ӣ��"),
    SpecialMonster       UMETA(DisplayName = "SpecialMonster", ToolTip = "�����"),
    SummonMonster        UMETA(DisplayName = "SummonMonster", ToolTip = "�ٻ���"),
    BossMonster          UMETA(DisplayName = "BossMonster", ToolTip = "Boss��"),
    InvincibleBossMonster UMETA(DisplayName = "InvincibleBossMonster", ToolTip = "����Ѫ��Boss��"),

};



USTRUCT(BlueprintType)
struct FMonsterGeneticData
{
    GENERATED_BODY()

        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Monster")
        ACharacter* MonsterCharacter;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Monster")
        EMonsterType MonsterType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Monster")
        EMDMoveType MonsterMoveType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Monster")
        EMDElementType  MonsterElementType;

        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Monster", , Meta = (DisplayName = "MonsterPower", ToolTip = "CurrentMonsterPower=Monster lv.1 Power *levelpowerfactor*wavediffcultyfactor "))
            float MonsterPower;

};