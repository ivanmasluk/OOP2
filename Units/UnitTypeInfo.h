#pragma once

#include "UnitType.h"
#include <optional>
#include <string_view>

enum class UnitCategory {
    Infantry,
    Archer,
    Cavalry,
    Unknown
};

struct UnitTypeInfo {
    UnitType type;
    const char* name;
    UnitCategory category;
    bool isHeavy;
};

const UnitTypeInfo& getUnitTypeInfo(UnitType type);

std::optional<UnitType> unitTypeFromString(std::string_view name);
