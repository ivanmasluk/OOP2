#include "EnergySource.h"

EnergySource::EnergySource(std::shared_ptr<IInteractionStrategy> strategy)
    : strategy_(std::move(strategy)) {
}

void EnergySource::interact(Unit& unit) {
    if (strategy_) {
        strategy_->apply(unit);
    }
}

char EnergySource::getSymbol() const {
    return 'E';
}
