#pragma once

#include "Terrain.h"

class Forest : public Terrain {
public:
    bool isPassable(UnitType type) const override;
    double getSpeedModifier(UnitType type) const override;
    int getDefenseBonus(UnitType type) const override;
    char getSymbol() const override;
};
