//
// File: Sun.cpp
// Author: NgocPT <kyvophonge@gmail.com>
// Created: 2025-10-28 09:16:09
//

#include "Sun.hpp"

Sun::Sun(double baseEnergy) : baseEnergy(baseEnergy) {}

double Sun::update(Time &time) { return energy = sin(time.time) + baseEnergy; }
