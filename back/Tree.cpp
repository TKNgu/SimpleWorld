//
// File: Tree.cpp
// Author: NgocPT <kyvophonge@gmail.com>
// Created: 2025-10-28 11:01:56
//

#include "Tree.hpp"

#include <iostream>

Tree::Tree(const TreeData &data) : MapTile(), data(data) {}

Tree::Tree(const Location &location) : MapTile(location) {}

void Tree::update(Context *context) {
  data.sumEnergy += context->sun.energy;
  if (data.sumEnergy >= data.splitEnergyPoint) {
    TreeData data = {
        .sumEnergy = this->data.sumEnergy - this->data.splitEnergyPoint,
        .splitEnergyPoint = this->data.splitEnergyPoint,
    };
    context->add(std::make_shared<Tree>(data));
  }
  std::cout << "sumEnergy " << data.sumEnergy << std::endl;
}

bool Tree::needRemove() { return data.sumEnergy <= 0; }
