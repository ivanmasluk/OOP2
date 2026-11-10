#include "Altar.h"

Altar::Altar(std::shared_ptr<IInteractionStrategy> strategy)
    : strategy_(std::move(strategy)) {
}

void Altar::interact(Unit& unit) {
    if (strategy_) {
        strategy_->apply(unit);
    }
}

char Altar::getSymbol() const {
    return 'A';
}
