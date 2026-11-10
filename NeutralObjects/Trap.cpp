#include "Trap.h"

Trap::Trap(std::shared_ptr<IInteractionStrategy> strategy)
    : strategy_(std::move(strategy)) {
}

void Trap::interact(Unit& unit) {
    if (strategy_) {
        strategy_->apply(unit);
    }
}

char Trap::getSymbol() const {
    return 'T';
}
