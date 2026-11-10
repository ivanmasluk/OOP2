#include "HealthRestoreStrategy.h"
#include "../Units/Unit.h"
#include <iostream>

void HealthRestoreStrategy::apply(Unit& unit) {
    const int before = unit.getHealth().getValue();
    unit.fullHeal();
    std::cout << unit.getType() << " восстановил здоровье ("
              << before << " -> " << unit.getHealth().getValue() << ")\n";
}
