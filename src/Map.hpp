//
// File: Map.hpp
// Author: NgocPT <kyvophonge@gmail.com>
// Created: 2025-10-28 09:07:06
//

#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <vector>

#include "Location.hpp"
#include "MapTile.hpp"

struct Map {
  int sizeX;
  int sizeY;
  std::vector<std::shared_ptr<MapTile>> map;

  Map(int, int);
  std::shared_ptr<MapTile> getMapTile(int, int);
  void setMapTile(int, int, std::shared_ptr<MapTile>);
  void setMapTile(const Location &, std::shared_ptr<MapTile>);
  Location getRandomLocation();
  bool checkLocation(const Location &);
  void remove(const Location &);
};

#endif // MAP_HPP
