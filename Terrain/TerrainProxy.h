#pragma once

#include "Terrain.h"

class TerrainProxy : public Terrain {
private:
    const Terrain* terrain_;

public:
    explicit TerrainProxy(const Terrain& terrain);

    bool isPassable(UnitType type) const override;
    double getSpeedModifier(UnitType type) const override;
    int getDefenseBonus(UnitType type) const override;
    char getSymbol() const override;
};
