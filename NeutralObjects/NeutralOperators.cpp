#include "NeutralOperators.h"

Unit& operator+(Unit& unit, TreasureChest& chest) {
    chest.interact(unit);
    return unit;
}

Unit& operator-(Unit& unit, Trap& trap) {
    trap.interact(unit);
    return unit;
}

Unit& operator*(Unit& unit, Altar& altar) {
    altar.interact(unit);
    return unit;
}

Unit& operator/(Unit& unit, EnergySource& source) {
    source.interact(unit);
    return unit;
}
