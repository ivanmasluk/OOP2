#include "AttackBoostStrategy.h"
#include "../Units/Unit.h"
#include <iostream>

AttackBoostStrategy::AttackBoostStrategy(int bonus)
    : bonus_(bonus) {
}

void AttackBoostStrategy::apply(Unit& unit) {
    const int oldValue = unit.getAttack().getValue();
    unit.boostAttack(bonus_);
    std::cout << unit.getType() << " получил +" << bonus_
              << " к атаке (" << oldValue << " -> "
              << unit.getAttack().getValue() << ")\n";
}
