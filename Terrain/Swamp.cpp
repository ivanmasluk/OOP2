#include "Swamp.h"

bool Swamp::isPassable(UnitType ) const {
    return true;
}

double Swamp::getSpeedModifier(UnitType ) const {
    return 0.5;
}

int Swamp::getDefenseBonus(UnitType ) const {
    return 0;
}

char Swamp::getSymbol() const {
    return '~';
}
