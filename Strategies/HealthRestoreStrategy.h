#pragma once

#include "IInteractionStrategy.h"

class HealthRestoreStrategy : public IInteractionStrategy {
public:
    void apply(Unit& unit) override;
};
