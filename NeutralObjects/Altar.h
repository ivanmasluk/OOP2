#pragma once

#include "NeutralObject.h"
#include "../Strategies/IInteractionStrategy.h"
#include <memory>

class Altar : public NeutralObject {
public:
    explicit Altar(std::shared_ptr<IInteractionStrategy> strategy);
    void interact(Unit& unit) override;
    char getSymbol() const override;

private:
    std::shared_ptr<IInteractionStrategy> strategy_;
};
