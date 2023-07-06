#pragma once

#include "CoreMinimal.h"
#include "MDMoveType.generated.h"

// ����Ԫ������ö��
    UENUM(BlueprintType)
        enum class EMDMoveType : uint8
    {
        Ground  UMETA(DisplayName = "Ground", ToolTip = "�����ƶ�"),
        GroundFire  UMETA(DisplayName = "GroundFire", ToolTip = "��������Ե�λ���Է��ÿ��ƶ�Ground fire units can placeable or  movable. "),
        GroundIce  UMETA(DisplayName = "GroundIce", ToolTip = "��������Ե�λ���Է��ÿ��ƶ�Ground ice units can placeable or  movable. "),
        GroundLightning  UMETA(DisplayName = "GroundLightning", ToolTip = "�����׵����Ե�λ���Է��ÿ��ƶ�Ground lightning units can placeable or  movable. "),
        GroundEarth  UMETA(DisplayName = "GroundEarth", ToolTip = "���������Ե�λ���Է��ÿ��ƶ�Ground earth units can placeable or  movable. "),
        GroundWind  UMETA(DisplayName = "GroundWind", ToolTip = "��������Ե�λ���Է��ÿ��ƶ�Ground wind units can placeable or  movable. "),
        GroundLight  UMETA(DisplayName = "GroundLight", ToolTip = "��������Ե�λ���Է��ÿ��ƶ�Ground light units can placeable or  movable. "),
        GroundDark  UMETA(DisplayName = "GroundDark", ToolTip = "���氵���Ե�λ���Է��ÿ��ƶ�Ground dark units can placeable or  movable. "),
        GroundNature  UMETA(DisplayName = "GroundNature", ToolTip = "������Ȼ���Ե�λ���Է��ÿ��ƶ�Ground nature units can placeable or  movable. "),
        Air          UMETA(DisplayName = "Air ", ToolTip = "�����ƶ�"),
        AirFire  UMETA(DisplayName = "AirFire", ToolTip = "���л����Ե�λ���Է��ÿ��ƶ�Air fire units can placeable or  movable. "),
        AirIce  UMETA(DisplayName = "AirIce", ToolTip = "���б����Ե�λ���Է��ÿ��ƶ�Air ice units can placeable or  movable. "),
        AirLightning  UMETA(DisplayName = "AirLightning", ToolTip = "�����׵����Ե�λ���Է��ÿ��ƶ�Air lightning units can placeable or  movable. "),
        AirEarth  UMETA(DisplayName = "AirEarth", ToolTip = "���������Ե�λ���Է��ÿ��ƶ�Air earth units can placeable or  movable. "),
        AirWind  UMETA(DisplayName = "AirWind", ToolTip = "���з����Ե�λ���Է��ÿ��ƶ�Air wind units can placeable or  movable. "),
        AirLight  UMETA(DisplayName = "AirLight", ToolTip = "���й����Ե�λ���Է��ÿ��ƶ�Air light units can placeable or  movable. "),
        AirDark  UMETA(DisplayName = "AirDark", ToolTip = "���а����Ե�λ���Է��ÿ��ƶ�Air dark units can placeable or  movable. "),
        AirNature  UMETA(DisplayName = "AirNature", ToolTip = "������Ȼ���Ե�λ���Է��ÿ��ƶ�Air nature units can placeable or  movable. "),
        Water  UMETA(DisplayName = "Water", ToolTip = "ˮ���ƶ�"),
        WaterIce  UMETA(DisplayName = "WaterIce", ToolTip = "ˮ�б����Ե�λ���Է��ÿ��ƶ�Water ice units can placeable or  movable. "),
        WaterLightning  UMETA(DisplayName = "WaterLightning", ToolTip = "ˮ���׵����Ե�λ���Է��ÿ��ƶ�Water lightning units can placeable or  movable. "),
        WaterLight  UMETA(DisplayName = "WaterLight", ToolTip = "ˮ�й����Ե�λ���Է��ÿ��ƶ�Water light units can placeable or  movable. "),
        WaterDark  UMETA(DisplayName = "WaterDark", ToolTip = "ˮ�а����Ե�λ���Է��ÿ��ƶ�Water dark units can placeable or  movable. "),
       

    };

