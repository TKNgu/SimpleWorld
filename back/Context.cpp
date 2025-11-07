//
// File: Context.cpp
// Author: NgocPT <kyvophonge@gmail.com>
// Created: 2025-10-28 09:10:38
//

#include "Context.hpp"

#include <format>
#include <iostream>

Context::Context(Time time, Sun sun, Map map)
    : time(time), sun(sun), map(map) {}

void Context::update() {
  time.update();
  sun.update(time);
  auto size = mapTiles.size();
  if (size == 0) {
    return;
  }
  int index = rand() % size;
  int delta = rand() % 2 == 1 ? -1 : 1;
  std::vector<int> indexRemove;
  for (auto count = 0; count < size; count++) {
    mapTiles[index]->update(this);
    if (mapTiles[index]->needRemove()) {
      indexRemove.emplace_back(index);
    }
    index += delta;
    index %= size;
  }
  for (auto index : indexRemove) {
    auto item = mapTiles[index];
    map.remove(item->location);
    mapTiles[index] = nullptr;
  }
  int lastIndex = mapTiles.size() - 1;
  while (!mapTiles[lastIndex] || lastIndex >= 0) {
    lastIndex--;
  }
  if (lastIndex < 0) {
    return;
  }
  for (auto index = lastIndex - 1; index >= 0; index--) {
    if (!mapTiles[index]) {
      mapTiles[index] = mapTiles[lastIndex--];
    }
  }
}

std::string Context::str() {
  return std::format("Time {} energy {:1.3f} count {}", time.time, sun.energy,
                     mapTiles.size());
}

void Context::add(std::shared_ptr<MapTile> mapTile) {
  auto location = map.getRandomLocation();
  if (map.checkLocation(location)) {
    return;
  }
  mapTile->setLocation(location);
  map.setMapTile(location, mapTile);
  mapTiles.emplace_back(mapTile);
}
