//
// File: Location.hpp
// Author: NgocPT <kyvophonge@gmail.com>
// Created: 2025-10-28 11:03:55
//

#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <string>

struct Location {
  int x;
  int y;

  Location(int = 0, int = 0);
  std::string str();
};

#endif // LOCATION_HPP
