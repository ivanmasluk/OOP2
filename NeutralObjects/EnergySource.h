#pragma once

#include "NeutralObject.h"
#include "../Strategies/IInteractionStrategy.h"
#include <memory>

class EnergySource : public NeutralObject {
public:
    explicit EnergySource(std::shared_ptr<IInteractionStrategy> strategy);
    void interact(Unit& unit) override;
    char getSymbol() const override;

private:
    std::shared_ptr<IInteractionStrategy> strategy_;
};
