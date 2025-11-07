//
// File: Location.cpp
// Author: NgocPT <kyvophonge@gmail.com>
// Created: 2025-10-28 11:05:19
//

#include "Location.hpp"

#include <format>

Location::Location(int x, int y) : x(x), y(y) {}

std::string Location::str() { return std::format("({}; {})", x, y); }
