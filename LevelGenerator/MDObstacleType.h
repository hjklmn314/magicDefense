#pragma once

#include "CoreMinimal.h"
#include "MDObstacleType.generated.h"

// 技能元素类型枚举

    UENUM(BlueprintType)
    enum class EMDObstacleType : uint8
{
    WoodenObstacle  UMETA(DisplayName = " WoodenObstacle ", ToolTip = "木制障碍物"),
    StoneObstacle   UMETA(DisplayName = "StoneObstacle", ToolTip = "石块"),
    iceObstacle  UMETA(DisplayName = "iceObstacle", ToolTip = "冰块"),
    MetalObstacle     UMETA(DisplayName = "MetalObstacle", ToolTip = "金属障碍物"),
    StatueObstacle   UMETA(DisplayName = "StatueObstacle", ToolTip = "Light雕像障碍物"),
    PoisonousObstacle  UMETA(DisplayName = "PoisonousObstacle", ToolTip = "毒障碍物"),
    CursedObstacle  UMETA(DisplayName = "CursedObstacle", ToolTip = "诅咒障碍物"),
    FixedFlaming  UMETA(DisplayName = "FixedFlaming", ToolTip = "火炬"),
    ElectrifiedObstacle UMETA(DisplayName = "ElectrifiedObstacle", ToolTip = "电磁障碍物"),
};

