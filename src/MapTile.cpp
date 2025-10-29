//
// File: MapTile.cpp
// Author: NgocPT <kyvophonge@gmail.com>
// Created: 2025-10-28 09:25:58
//

#include "MapTile.hpp"

#include <format>

MapTile::MapTile() {}

MapTile::MapTile(const Location &location) : location(location) {}

MapTile::MapTile(int x, int y) : location(x, y) {}

std::string MapTile::str() { return location.str(); }

void MapTile::setLocation(const Location &location) {
  this->location = location;
}

bool MapTile::needRemove() { return false; }
