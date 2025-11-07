//
// File: main.cpp
// Author: NgocPT <kyvophonge@gmail.com>
// Created: 2025-10-28 09:19:32
//

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

#define WORLD_SIZE_X 1024
#define WORLD_SIZE_Y 1024

#include "Context.hpp"
#include "Map.hpp"
#include "Sun.hpp"
#include "Time.hpp"
#include "Tree.hpp"

int main() {
  srand(time(0));
  auto context = std::make_shared<Context>(Time(0, 0.5), Sun(0.5),
                                           Map(WORLD_SIZE_X, WORLD_SIZE_Y));
  context->add(std::make_shared<Tree>(TreeData{}));

  int test = 100;
  bool isRunning = true;
  while (isRunning && test-- >= 0) {
    context->update();
    std::cout << context->str() << std::endl;
  }
  return 0;
}
