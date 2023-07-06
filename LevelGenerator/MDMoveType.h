#pragma once

#include "CoreMinimal.h"
#include "MDMoveType.generated.h"

// 技能元素类型枚举
    UENUM(BlueprintType)
        enum class EMDMoveType : uint8
    {
        Ground  UMETA(DisplayName = "Ground", ToolTip = "地面移动"),
        GroundFire  UMETA(DisplayName = "GroundFire", ToolTip = "地面火属性单位可以放置可移动Ground fire units can placeable or  movable. "),
        GroundIce  UMETA(DisplayName = "GroundIce", ToolTip = "地面冰属性单位可以放置可移动Ground ice units can placeable or  movable. "),
        GroundLightning  UMETA(DisplayName = "GroundLightning", ToolTip = "地面雷电属性单位可以放置可移动Ground lightning units can placeable or  movable. "),
        GroundEarth  UMETA(DisplayName = "GroundEarth", ToolTip = "地面土属性单位可以放置可移动Ground earth units can placeable or  movable. "),
        GroundWind  UMETA(DisplayName = "GroundWind", ToolTip = "地面风属性单位可以放置可移动Ground wind units can placeable or  movable. "),
        GroundLight  UMETA(DisplayName = "GroundLight", ToolTip = "地面光属性单位可以放置可移动Ground light units can placeable or  movable. "),
        GroundDark  UMETA(DisplayName = "GroundDark", ToolTip = "地面暗属性单位可以放置可移动Ground dark units can placeable or  movable. "),
        GroundNature  UMETA(DisplayName = "GroundNature", ToolTip = "地面自然属性单位可以放置可移动Ground nature units can placeable or  movable. "),
        Air          UMETA(DisplayName = "Air ", ToolTip = "空中移动"),
        AirFire  UMETA(DisplayName = "AirFire", ToolTip = "空中火属性单位可以放置可移动Air fire units can placeable or  movable. "),
        AirIce  UMETA(DisplayName = "AirIce", ToolTip = "空中冰属性单位可以放置可移动Air ice units can placeable or  movable. "),
        AirLightning  UMETA(DisplayName = "AirLightning", ToolTip = "空中雷电属性单位可以放置可移动Air lightning units can placeable or  movable. "),
        AirEarth  UMETA(DisplayName = "AirEarth", ToolTip = "空中土属性单位可以放置可移动Air earth units can placeable or  movable. "),
        AirWind  UMETA(DisplayName = "AirWind", ToolTip = "空中风属性单位可以放置可移动Air wind units can placeable or  movable. "),
        AirLight  UMETA(DisplayName = "AirLight", ToolTip = "空中光属性单位可以放置可移动Air light units can placeable or  movable. "),
        AirDark  UMETA(DisplayName = "AirDark", ToolTip = "空中暗属性单位可以放置可移动Air dark units can placeable or  movable. "),
        AirNature  UMETA(DisplayName = "AirNature", ToolTip = "空中自然属性单位可以放置可移动Air nature units can placeable or  movable. "),
        Water  UMETA(DisplayName = "Water", ToolTip = "水中移动"),
        WaterIce  UMETA(DisplayName = "WaterIce", ToolTip = "水中冰属性单位可以放置可移动Water ice units can placeable or  movable. "),
        WaterLightning  UMETA(DisplayName = "WaterLightning", ToolTip = "水中雷电属性单位可以放置可移动Water lightning units can placeable or  movable. "),
        WaterLight  UMETA(DisplayName = "WaterLight", ToolTip = "水中光属性单位可以放置可移动Water light units can placeable or  movable. "),
        WaterDark  UMETA(DisplayName = "WaterDark", ToolTip = "水中暗属性单位可以放置可移动Water dark units can placeable or  movable. "),
       

    };

