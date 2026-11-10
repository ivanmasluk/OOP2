#include "UnitTypeInfo.h"

const UnitTypeInfo& getUnitTypeInfo(UnitType type) {
    static const UnitTypeInfo swordsman{
        UnitType::Swordsman, "Swordsman", UnitCategory::Infantry, false
    };
    static const UnitTypeInfo spearman{
        UnitType::Spearman, "Spearman", UnitCategory::Infantry, false
    };
    static const UnitTypeInfo lightArcher{
        UnitType::LightArcher, "LightArcher", UnitCategory::Archer, false
    };
    static const UnitTypeInfo heavyArcher{
        UnitType::HeavyArcher, "HeavyArcher", UnitCategory::Archer, true
    };
    static const UnitTypeInfo cataphract{
        UnitType::Cataphract, "Cataphract", UnitCategory::Cavalry, true
    };
    static const UnitTypeInfo horseArcher{
        UnitType::HorseArcher, "HorseArcher", UnitCategory::Cavalry, false
    };

    switch (type) {
    case UnitType::Swordsman:   return swordsman;
    case UnitType::Spearman:    return spearman;
    case UnitType::LightArcher: return lightArcher;
    case UnitType::HeavyArcher: return heavyArcher;
    case UnitType::Cataphract:  return cataphract;
    case UnitType::HorseArcher: return horseArcher;
    }

    static const UnitTypeInfo unknown{
        UnitType::Swordsman, "Unknown", UnitCategory::Unknown, false
    };
    return unknown;
}

std::optional<UnitType> unitTypeFromString(std::string_view name) {
    if (name == "Swordsman")   return UnitType::Swordsman;
    if (name == "Spearman")    return UnitType::Spearman;
    if (name == "LightArcher") return UnitType::LightArcher;
    if (name == "HeavyArcher") return UnitType::HeavyArcher;
    if (name == "Cataphract")  return UnitType::Cataphract;
    if (name == "HorseArcher") return UnitType::HorseArcher;

    return std::nullopt;
}
