#include "DamageStrategy.h"
#include "../Units/Unit.h"
#include <iostream>

DamageStrategy::DamageStrategy(int damage)
    : damage_(damage) {
}

void DamageStrategy::apply(Unit& unit) {
    std::cout << unit.getType() << " попал в ловушку и получил "
              << damage_ << " урона\n";
    unit.takeDamage(damage_);
}
