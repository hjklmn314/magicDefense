#pragma once

#include "CoreMinimal.h"
#include "MDElementType.generated.h"

// ����Ԫ������ö��
UENUM(BlueprintType)
enum class EMDElementType : uint8
{
	Fire        UMETA(DisplayName = "Fire", ToolTip = "��Ԫ��"),
	Ice         UMETA(DisplayName = "Ice", ToolTip = "��Ԫ��"),
	Lightning   UMETA(DisplayName = "Lightning", ToolTip = "�׵�Ԫ��"),
	Earth       UMETA(DisplayName = "Earth", ToolTip = "����Ԫ��"),
	Wind        UMETA(DisplayName = "Wind", ToolTip = "��Ԫ��"),
	Light       UMETA(DisplayName = "Light", ToolTip = "��Ԫ��"),
	Dark        UMETA(DisplayName = "Dark", ToolTip = "��Ԫ��"),
	Nature      UMETA(DisplayName = "Nature", ToolTip = "��Ȼϵ"),
	Physic      UMETA(DisplayName = "Physic", ToolTip = "����"),
};
