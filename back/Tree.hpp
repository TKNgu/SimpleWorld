//
// File: Tree.hpp
// Author: NgocPT <kyvophonge@gmail.com>
// Created: 2025-10-28 11:01:06
//

#ifndef TREE_HPP
#define TREE_HPP

#include <memory>

#include "Context.hpp"
#include "Location.hpp"
#include "MapTile.hpp"

struct TreeData {
  double sumEnergy = 0;
  double splitEnergyPoint = 50.0;
};

struct Tree : MapTile {
  TreeData data;

  Tree(const TreeData &);
  Tree(const Location &);
  void update(Context *) override;
  bool needRemove() override;
};

#endif // TREE_HPP
