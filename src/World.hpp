//
// File: World.hpp
// Author: NgocPT <kyvophonge@gmail.com>
// Created: 2025-10-31 16:20:02
//

#ifndef WORLD_HPP
#define WORLD_HPP

#include "Land.hpp"
#include "Sun.hpp"
#include "Time.hpp"

struct World {
  Time time;
  Sun sun;
  Land land;
};

#endif // WORLD_HPP
