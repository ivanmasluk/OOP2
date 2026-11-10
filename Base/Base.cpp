#include "Base.h"
#include <iostream>

Base::Base(int x, int y, int health, size_t maxUnits, int defenseLevel, int resources)
    : x_(x),
      y_(y),
      health_(health),
      maxUnits_(maxUnits),
      defenseLevel_(defenseLevel),
      resources_(resources),
      livingUnits_(0) {
}

int Base::getX() const {
    return x_;
}

int Base::getY() const {
    return y_;
}

int Base::getHealth() const {
    return health_;
}

size_t Base::getMaxUnits() const {
    return maxUnits_;
}

size_t Base::getLivingUnits() const {
    return livingUnits_;
}

int Base::getDefenseLevel() const {
    return defenseLevel_;
}

int Base::getResources() const {
    return resources_;
}

void Base::addResources(int amount) {
    if (amount < 0) {
        amount = 0;
    }
    resources_ += amount;
}

bool Base::canCreateUnit() const {
    return livingUnits_ < maxUnits_;
}

bool Base::createUnit(UnitFactory& factory,
                      const std::string& type,
                      GameField& field,
                      int x,
                      int y) {
    if (!canCreateUnit()) {
        std::cout << "[Base] Лимит юнитов достигнут\n";
        return false;
    }

    std::unique_ptr<Unit> unit = factory.createUnit(type);
    if (!unit) {
        std::cout << "[Base] Неизвестный тип юнита: " << type << "\n";
        return false;
    }

    Unit* raw = unit.get();
    raw->subscribe(this);

    if (!field.addUnit(std::move(unit), x, y)) {
        std::cout << "[Base] Не удалось разместить юнита на поле\n";
        return false;
    }

    unitIds_.push_back(raw->getId());
    ++livingUnits_;

    UnitEvent created{
        UnitEventType::Created,
        raw->getId(),
        raw->getType(),
        0
    };
    onUnitEvent(created);

    return true;
}

void Base::onUnitEvent(const UnitEvent& event) {
    if (event.type == UnitEventType::Created) {
        std::cout << "[Base] Юнит создан: " << event.unitTypeName
                  << " id=" << event.unitId
                  << " (живых: " << livingUnits_ << ")\n";
        return;
    }

    if (event.type == UnitEventType::Damaged) {
        std::cout << "[Base] Юнит id=" << event.unitId
                  << " (" << event.unitTypeName << ") получил урон: "
                  << event.damage << "\n";
        return;
    }

    if (event.type == UnitEventType::Destroyed) {
        if (livingUnits_ > 0) {
            --livingUnits_;
        }
        std::cout << "[Base] Юнит уничтожен: " << event.unitTypeName
                  << " id=" << event.unitId
                  << " (живых: " << livingUnits_ << ")\n";
    }
}
