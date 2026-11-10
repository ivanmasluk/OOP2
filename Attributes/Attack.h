#pragma once

class Armor;  

class Attack {
private:
    int value_;

public:
    explicit Attack(int value = 10);

    int getValue() const;
    void setValue(int value);
    int calculateDamage(const Armor& targetArmor) const;
};
