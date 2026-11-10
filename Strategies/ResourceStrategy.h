#pragma once

#include "IInteractionStrategy.h"

class Base;

class ResourceStrategy : public IInteractionStrategy {
public:
    ResourceStrategy(Base* base, int amount = 50);
    void apply(Unit& unit) override;

private:
    Base* base_;
    int amount_;
};
