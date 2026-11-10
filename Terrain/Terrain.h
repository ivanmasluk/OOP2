#pragma once

#include "../Units/UnitType.h"

class Terrain {
public:
    virtual bool isPassable(UnitType type) const = 0;
    virtual double getSpeedModifier(UnitType type) const = 0;
    virtual int getDefenseBonus(UnitType type) const = 0;
    virtual char getSymbol() const = 0;
    virtual ~Terrain() = default;
};
