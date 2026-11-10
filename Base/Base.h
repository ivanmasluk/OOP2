#pragma once

#include "../Events/IObserver.h"
#include "../Factories/UnitFactory.h"
#include "../GameField.h"
#include <memory>
#include <string>
#include <vector>

class Base : public IObserver {
private:
    int x_;
    int y_;
    int health_;
    size_t maxUnits_;
    int defenseLevel_;
    int resources_;
    size_t livingUnits_;
    std::vector<int> unitIds_;

public:
    Base(int x, int y, int health, size_t maxUnits, int defenseLevel, int resources = 0);

    int getX() const;
    int getY() const;
    int getHealth() const;
    size_t getMaxUnits() const;
    size_t getLivingUnits() const;
    int getDefenseLevel() const;
    int getResources() const;

    void addResources(int amount);
    bool canCreateUnit() const;

    bool createUnit(UnitFactory& factory,
                    const std::string& type,
                    GameField& field,
                    int x,
                    int y);

    void onUnitEvent(const UnitEvent& event) override;
};
