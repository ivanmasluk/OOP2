#include "Plains.h"

bool Plains::isPassable(UnitType ) const {
    return true;
}

double Plains::getSpeedModifier(UnitType ) const {
    return 1.0;
}

int Plains::getDefenseBonus(UnitType ) const {
    return 0;
}

char Plains::getSymbol() const {
    return '.';
}
