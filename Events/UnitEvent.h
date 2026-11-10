#pragma once

#include <string>

enum class UnitEventType {
    Created,
    Damaged,
    Destroyed
};

struct UnitEvent {
    UnitEventType type;
    int unitId;
    std::string unitTypeName;
    int damage;
};
