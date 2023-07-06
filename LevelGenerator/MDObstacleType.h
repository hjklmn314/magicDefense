#pragma once

#include "CoreMinimal.h"
#include "MDObstacleType.generated.h"

// ����Ԫ������ö��

    UENUM(BlueprintType)
    enum class EMDObstacleType : uint8
{
    WoodenObstacle  UMETA(DisplayName = " WoodenObstacle ", ToolTip = "ľ���ϰ���"),
    StoneObstacle   UMETA(DisplayName = "StoneObstacle", ToolTip = "ʯ��"),
    iceObstacle  UMETA(DisplayName = "iceObstacle", ToolTip = "����"),
    MetalObstacle     UMETA(DisplayName = "MetalObstacle", ToolTip = "�����ϰ���"),
    StatueObstacle   UMETA(DisplayName = "StatueObstacle", ToolTip = "Light�����ϰ���"),
    PoisonousObstacle  UMETA(DisplayName = "PoisonousObstacle", ToolTip = "���ϰ���"),
    CursedObstacle  UMETA(DisplayName = "CursedObstacle", ToolTip = "�����ϰ���"),
    FixedFlaming  UMETA(DisplayName = "FixedFlaming", ToolTip = "���"),
    ElectrifiedObstacle UMETA(DisplayName = "ElectrifiedObstacle", ToolTip = "����ϰ���"),
};

