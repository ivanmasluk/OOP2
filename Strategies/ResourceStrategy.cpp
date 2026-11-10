#include "ResourceStrategy.h"
#include "../Base/Base.h"
#include "../Units/Unit.h"
#include <iostream>

ResourceStrategy::ResourceStrategy(Base* base, int amount)
    : base_(base), amount_(amount) {
}

void ResourceStrategy::apply(Unit& unit) {
    if (base_ == nullptr) {
        return;
    }
    base_->addResources(amount_);
    std::cout << unit.getType() << " собрал ресурсы: +"
              << amount_ << " (всего у базы: "
              << base_->getResources() << ")\n";
}
