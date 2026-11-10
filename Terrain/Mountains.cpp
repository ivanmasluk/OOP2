#include "Mountains.h"

bool Mountains::isPassable(UnitType ) const {
    return false;
}

double Mountains::getSpeedModifier(UnitType ) const {
    return 1.0;
}

int Mountains::getDefenseBonus(UnitType ) const {
    return 0;
}

char Mountains::getSymbol() const {
    return '^';
}
