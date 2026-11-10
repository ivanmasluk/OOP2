#pragma once

#include "IInteractionStrategy.h"

class AttackBoostStrategy : public IInteractionStrategy {
public:
    explicit AttackBoostStrategy(int bonus = 10);
    void apply(Unit& unit) override;

private:
    int bonus_;
};
