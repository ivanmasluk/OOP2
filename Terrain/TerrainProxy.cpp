#include "TerrainProxy.h"

#include <iostream>
#include "../Units/UnitTypeInfo.h"

TerrainProxy::TerrainProxy(const Terrain& terrain)
    : terrain_(&terrain) {
}

bool TerrainProxy::isPassable(UnitType type) const {
    const bool result = terrain_->isPassable(type);

    if (!result) {
        std::cout << "[TerrainProxy] "
                  << getUnitTypeInfo(type).name
                  << " не может пройти через этот ландшафт.\n";
    }

    return result;
}

double TerrainProxy::getSpeedModifier(UnitType type) const {
    const double modifier = terrain_->getSpeedModifier(type);

    if (modifier != 1.0) {
        std::cout << "[TerrainProxy] Коэффициент скорости: "
                  << modifier << "\n";
    }

    return modifier;
}

int TerrainProxy::getDefenseBonus(UnitType type) const {
    const int bonus = terrain_->getDefenseBonus(type);

    if (bonus != 0) {
        std::cout << "[TerrainProxy] Бонус защиты: +"
                  << bonus << "\n";
    }

    return bonus;
}

char TerrainProxy::getSymbol() const {
    return terrain_->getSymbol();
}
