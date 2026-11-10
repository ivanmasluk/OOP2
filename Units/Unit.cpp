#include "Unit.h"
#include <algorithm>

int Unit::nextId_ = 1;

Unit::Unit(const Health& health, const Armor& armor, const Attack& attack)
    : id_(nextId_++),
      health_(health),
      armor_(armor),
      attack_(attack),
      maxHealth_(health.getValue()) {
}

int Unit::getId() const {
    return id_;
}

const Health& Unit::getHealth() const {
    return health_;
}

const Armor& Unit::getArmor() const {
    return armor_;
}

const Attack& Unit::getAttack() const {
    return attack_;
}

int Unit::getX() const {
    return x_;
}

int Unit::getY() const {
    return y_;
}

bool Unit::isAlive() const {
    return !health_.isZero();
}

void Unit::setPosition(int x, int y) {
    x_ = x;
    y_ = y;
}

void Unit::move(int dx, int dy) {
    x_ += dx;
    y_ += dy;
}

void Unit::takeDamage(int rawDamage) {
    if (rawDamage < 0) {
        rawDamage = 0;
    }

    const int actualDamage = armor_.reduceDamage(rawDamage);
    health_.decrease(actualDamage);

    UnitEvent damagedEvent{
        UnitEventType::Damaged,
        id_,
        getType(),
        actualDamage
    };
    notify(damagedEvent);

    if (health_.isZero()) {
        UnitEvent destroyedEvent{
            UnitEventType::Destroyed,
            id_,
            getType(),
            actualDamage
        };
        notify(destroyedEvent);
    }
}

void Unit::boostAttack(int amount) {
    if (amount < 0) {
        amount = 0;
    }
    attack_.setValue(attack_.getValue() + amount);
}

void Unit::fullHeal() {
    health_.setValue(maxHealth_);
}

void Unit::subscribe(IObserver* observer) {
    if (observer == nullptr) {
        return;
    }
    if (std::find(observers_.begin(), observers_.end(), observer) == observers_.end()) {
        observers_.push_back(observer);
    }
}

void Unit::unsubscribe(IObserver* observer) {
    observers_.erase(
        std::remove(observers_.begin(), observers_.end(), observer),
        observers_.end()
    );
}

void Unit::notify(const UnitEvent& event) {
    for (IObserver* observer : observers_) {
        if (observer != nullptr) {
            observer->onUnitEvent(event);
        }
    }
}
