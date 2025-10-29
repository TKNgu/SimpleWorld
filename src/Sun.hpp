//
// File: Sun.hpp
// Author: NgocPT <kyvophonge@gmail.com>
// Created: 2025-10-28 09:08:46
//

#ifndef SUN_HPP
#define SUN_HPP

#include <cmath>

#include "Time.hpp"

struct Sun {
  double baseEnergy;
  double energy;

  Sun(double = 1);
  double update(Time &);
};

#endif // SUN_HPP
