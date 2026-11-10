#pragma once

#include "../Units/Unit.h"
#include "TreasureChest.h"
#include "Trap.h"
#include "Altar.h"
#include "EnergySource.h"

Unit& operator+(Unit& unit, TreasureChest& chest);
Unit& operator-(Unit& unit, Trap& trap);
Unit& operator*(Unit& unit, Altar& altar);
Unit& operator/(Unit& unit, EnergySource& source);
