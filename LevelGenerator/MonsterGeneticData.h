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
	NormalMonster        UMETA(DisplayName = "NormalMonster", ToolTip = "ÆÕÍ¨¹Ö"),
    AdvancedMonster      UMETA(DisplayName = "AdvancedMonster", ToolTip = "½ø½×¹Ö"),
    EliteMonster         UMETA(DisplayName = "EliteMonster", ToolTip = "¾«Ó¢¹Ö"),
    SpecialMonster       UMETA(DisplayName = "SpecialMonster", ToolTip = "ÌØÊâ¹Ö"),
    SummonMonster        UMETA(DisplayName = "SummonMonster", ToolTip = "ÕÙ»½¹Ö"),
    BossMonster          UMETA(DisplayName = "BossMonster", ToolTip = "Boss¹Ö"),
    InvincibleBossMonster UMETA(DisplayName = "InvincibleBossMonster", ToolTip = "ÎÞÏÞÑªÁ¿Boss¹Ö"),

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