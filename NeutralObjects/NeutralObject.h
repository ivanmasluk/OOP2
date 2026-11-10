#pragma once

class Unit;

class NeutralObject {
public:
    virtual ~NeutralObject() = default;
    virtual void interact(Unit& unit) = 0;
    virtual char getSymbol() const = 0;
};
