//
// File: Context.hpp
// Author: NgocPT <kyvophonge@gmail.com>
// Created: 2025-10-28 09:09:11
//

#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <string>

#include "Map.hpp"
#include "MapTile.hpp"
#include "Sun.hpp"
#include "Time.hpp"

struct Context {
  Time time;
  Sun sun;
  Map map;
  std::vector<std::shared_ptr<MapTile>> mapTiles;

  Context(Time, Sun, Map);
  std::string str();
  void update();
  void add(std::shared_ptr<MapTile>);
};

#endif // CONTEXT_HPP
