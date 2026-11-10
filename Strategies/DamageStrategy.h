#pragma once

#include "IInteractionStrategy.h"

class DamageStrategy : public IInteractionStrategy {
public:
    explicit DamageStrategy(int damage = 40);
    void apply(Unit& unit) override;

private:
    int damage_;
};
