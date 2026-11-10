#pragma once

#include "../Attributes/Health.h"
#include "../Attributes/Armor.h"
#include "../Attributes/Attack.h"
#include "../Events/IObservable.h"
#include <memory>
#include <string>
#include <vector>

class Unit : public IObservable {
protected:
    int id_;
    Health health_;
    Armor armor_;
    Attack attack_;
    int maxHealth_;
    int x_ = 0;
    int y_ = 0;
    std::vector<IObserver*> observers_;
    static int nextId_;

public:
    Unit(const Health& health, const Armor& armor, const Attack& attack);
    virtual ~Unit() = default;

    int getId() const;
    const Health& getHealth() const;
    const Armor& getArmor() const;
    const Attack& getAttack() const;
    int getX() const;
    int getY() const;
    bool isAlive() const;

    void setPosition(int x, int y);
    void move(int dx, int dy);

    void takeDamage(int rawDamage);
    void boostAttack(int amount);
    void fullHeal();

    void subscribe(IObserver* observer) override;
    void unsubscribe(IObserver* observer) override;
    void notify(const UnitEvent& event) override;

    virtual std::unique_ptr<Unit> clone() const = 0;
    virtual std::string getType() const = 0;
};
