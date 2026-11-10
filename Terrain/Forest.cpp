#include "Forest.h"
#include "../Units/UnitTypeInfo.h"

bool Forest::isPassable(UnitType type) const {
    return !getUnitTypeInfo(type).isHeavy;
}

double Forest::getSpeedModifier(UnitType ) const {
    return 1.0;
}

int Forest::getDefenseBonus(UnitType ) const {
    return 10;
}

char Forest::getSymbol() const {
    return '*';
}
