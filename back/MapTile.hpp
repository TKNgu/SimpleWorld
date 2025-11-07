//
// File: MapTile.hpp
// Author: NgocPT <kyvophonge@gmail.com>
// Created: 2025-10-28 09:06:46
//

#ifndef MAPTILE_HPP
#define MAPTILE_HPP

#include <string>

#include "Location.hpp"

struct Context;

struct MapTile {
  Location location;

  MapTile();
  MapTile(const Location &);
  MapTile(int, int);
  std::string str();
  void setLocation(const Location &);
  virtual void update(Context *) = 0;
  virtual bool needRemove();
};

#endif // MAPTILE_HPP
