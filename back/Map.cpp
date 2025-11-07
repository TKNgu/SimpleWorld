//
// File: Map.cpp
// Author: NgocPT <kyvophonge@gmail.com>
// Created: 2025-10-28 09:26:34
//

#include <cstdlib>

#include "Map.hpp"

Map::Map(int sizeX, int sizeY)
    : sizeX(sizeX), sizeY(sizeY), map(sizeX * sizeY, nullptr) {}

std::shared_ptr<MapTile> Map::getMapTile(int x, int y) {
  return map[y * sizeX + x];
}

void Map::setMapTile(int x, int y, std::shared_ptr<MapTile> tile) {
  map[y * sizeX + x] = tile;
}

void Map::setMapTile(const Location &location,
                     std::shared_ptr<MapTile> mapTile) {
  map[location.y * sizeX + location.x] = mapTile;
}

Location Map::getRandomLocation() {
  return Location(rand() % sizeX, rand() % sizeY);
}

bool Map::checkLocation(const Location &location) {
  return bool(map[location.y * sizeX + location.x]);
}

void Map::remove(const Location &location) {
  map[location.y * sizeX + location.x] = nullptr;
}
