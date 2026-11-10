#include "TreasureChest.h"

TreasureChest::TreasureChest(std::shared_ptr<IInteractionStrategy> strategy)
    : strategy_(std::move(strategy)) {
}

void TreasureChest::interact(Unit& unit) {
    if (strategy_) {
        strategy_->apply(unit);
    }
}

char TreasureChest::getSymbol() const {
    return 'C';
}
