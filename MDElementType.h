#pragma once

#include "CoreMinimal.h"
#include "MDElementType.generated.h"

// 技能元素类型枚举
UENUM(BlueprintType)
enum class EMDElementType : uint8
{
	Fire        UMETA(DisplayName = "Fire", ToolTip = "火元素"),
	Ice         UMETA(DisplayName = "Ice", ToolTip = "冰元素"),
	Lightning   UMETA(DisplayName = "Lightning", ToolTip = "雷电元素"),
	Earth       UMETA(DisplayName = "Earth", ToolTip = "地面元素"),
	Wind        UMETA(DisplayName = "Wind", ToolTip = "风元素"),
	Light       UMETA(DisplayName = "Light", ToolTip = "光元素"),
	Dark        UMETA(DisplayName = "Dark", ToolTip = "暗元素"),
	Nature      UMETA(DisplayName = "Nature", ToolTip = "自然系"),
	Physic      UMETA(DisplayName = "Physic", ToolTip = "物理"),
};
