#include <iostream>
#include <memory>
#include <string>
#include <clocale>

#include "GameField.h"
#include "Factories/InfantryFactory.h"
#include "Factories/ArcherFactory.h"
#include "Factories/CavalryFactory.h"
#include "Terrain/TerrainMap.h"
#include "Base/Base.h"
#include "NeutralObjects/TreasureChest.h"
#include "NeutralObjects/Trap.h"
#include "NeutralObjects/Altar.h"
#include "NeutralObjects/EnergySource.h"
#include "NeutralObjects/NeutralOperators.h"
#include "Strategies/AttackBoostStrategy.h"
#include "Strategies/HealthRestoreStrategy.h"
#include "Strategies/DamageStrategy.h"
#include "Strategies/ResourceStrategy.h"
#include "Units/UnitType.h"

void printMap(const GameField& field, const TerrainMap& terrainMap) {
    const int width = field.getWidth();
    const int height = field.getHeight();

    for (int i = 0; i < width + 2; ++i) {
        std::cout << "X ";
    }
    std::cout << '\n';

    for (int y = 0; y < height; ++y) {
        std::cout << "X ";
        for (int x = 0; x < width; ++x) {
            const Unit* unit = field.getUnit(x, y);
            if (unit != nullptr) {
                std::cout << unit->getType()[0] << ' ';
            } else {
                std::cout << terrainMap.getSymbol(x, y) << ' ';
            }
        }
        std::cout << "X\n";
    }

    for (int i = 0; i < width + 2; ++i) {
        std::cout << "X ";
    }
    std::cout << '\n';
}

void fillDemoTerrain(TerrainMap& map) {
    const int width = map.getWidth();
    const int height = map.getHeight();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if ((x + y) % 5 == 0) {
                map.setTerrain(x, y, TerrainType::Forest);
            } else if ((x * 2 + y) % 7 == 0) {
                map.setTerrain(x, y, TerrainType::Swamp);
            } else if ((x + y * 3) % 11 == 0) {
                map.setTerrain(x, y, TerrainType::Mountains);
            } else {
                map.setTerrain(x, y, TerrainType::Plains);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, ".utf8");

    InfantryFactory infantryFactory;
    ArcherFactory archerFactory;
    CavalryFactory cavalryFactory;

    std::cout << "    Сценарий 1: база создаёт юнитов\n";

    GameField field(16, 12, 20);
    TerrainMap terrainMap(16, 12);
    fillDemoTerrain(terrainMap);

    Base base(0, 0, 500, 10, 5, 100);

    base.createUnit(infantryFactory, "Swordsman", field, 1, 0);
    base.createUnit(archerFactory, "LightArcher", field, 14, 0);
    base.createUnit(infantryFactory, "Spearman", field, 8, 5);
    base.createUnit(cavalryFactory, "Cataphract", field, 7, 9);
    base.createUnit(cavalryFactory, "HorseArcher", field, 15, 11);

    std::cout << "Живых у базы: " << base.getLivingUnits() << "\n";
    std::cout << "Ресурсы базы: " << base.getResources() << "\n";
    std::cout << "Карта (. равнина, * лес, ~ болото, ^ горы):\n";
    printMap(field, terrainMap);

    std::cout << "\n    Сценарий 2: ландшафт и TerrainProxy\n";

    double speed = 1.0;
    std::cout << "Swordsman пытается пройти на клетку:\n";
    field.moveUnit(1, 0, 2, 0, terrainMap, &speed);

    std::cout << "Cataphract (тяжёлый) в лес:\n";
    field.moveUnit(7, 9, 5, 5, terrainMap, &speed);

    std::cout << "LightArcher в горы:\n";
    field.moveUnit(14, 0, 3, 3, terrainMap, &speed);

    std::cout << "\n    Сценарий 3: нейтральные объекты и операторы\n";

    Unit* swordsman = field.getUnit(2, 0);
    if (swordsman == nullptr) {
        swordsman = field.getUnit(1, 0);
    }

    auto resourceStrategy = std::make_shared<ResourceStrategy>(&base, 40);
    auto damageStrategy = std::make_shared<DamageStrategy>(50);
    auto attackStrategy = std::make_shared<AttackBoostStrategy>(12);
    auto healStrategy = std::make_shared<HealthRestoreStrategy>();

    TreasureChest chest(resourceStrategy);
    Trap trap(damageStrategy);
    Altar altar(attackStrategy);
    EnergySource source(healStrategy);

    if (swordsman != nullptr) {
        std::cout << "До взаимодействия HP="
                  << swordsman->getHealth().getValue()
                  << " ATK=" << swordsman->getAttack().getValue() << "\n";

        *swordsman + chest;
        *swordsman - trap;
        *swordsman * altar;
        *swordsman / source;

        std::cout << "После взаимодействия HP="
                  << swordsman->getHealth().getValue()
                  << " ATK=" << swordsman->getAttack().getValue() << "\n";
        std::cout << "Ресурсы базы: " << base.getResources() << "\n";
    }

    std::cout << "\n    Сценарий 4: Observer — уничтожение юнита\n";

    Unit* target = field.getUnit(8, 5);
    if (target == nullptr) {
        for (auto& unit : field) {
            target = &unit;
            break;
        }
    }

    if (target != nullptr) {
        std::cout << "Атакуем " << target->getType()
                  << " id=" << target->getId() << "\n";
        target->takeDamage(1000);
        std::cout << "Живых у базы после боя: "
                  << base.getLivingUnits() << "\n";
    }

    std::cout << "\n    Сценарий 5: итоговое поле\n";
    printMap(field, terrainMap);

    return 0;
}
