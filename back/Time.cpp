//
// File: Time.cpp
// Author: NgocPT <kyvophonge@gmail.com>
// Created: 2025-10-28 09:22:23
//

#include "Time.hpp"

Time::Time(double time, double deltaTime) : time(time), deltaTime(deltaTime) {}

void Time::update() { time += deltaTime; }
