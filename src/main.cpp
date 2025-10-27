#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>

#define WORLD_SIZE_X 1024
#define WORLD_SIZE_Y 1024

struct MapTile {};

// struct MapTile {
//   int x;
//   int y;
//
//   MapTile(int x, int y) : x(x), y(y) {}
// };
//
// struct TreeCell : MapTile {
//   TreeCell(int x, int y) : MapTile(x, y) {}
// };
//
// struct Tree {
//   std::vector<std::shared_ptr<TreeCell>> treeCell;
//
//   Tree(int x, int y) {
//     treeCell.emplace_back(std::make_shared<TreeCell>(x, y));
//   }
//
//   Tree(std::shared_ptr<TreeCell> treeCell) {
//     this->treeCell.emplace_back(treeCell);
//   }
// };

struct Map {
  int sizeX;
  int sizeY;
  std::vector<std::shared_ptr<MapTile>> map;

  Map(int sizeX, int sizeY)
      : sizeX(sizeX), sizeY(sizeY), map(sizeX * sizeY, nullptr) {}

  std::shared_ptr<MapTile> getMapTile(int x, int y) {
    return map[y * sizeX + x];
  }

  void setMapTile(int x, int y, std::shared_ptr<MapTile> tile) {
    map[y * sizeX + x] = tile;
  }
};

struct Time {
  double time;
  double deltaTime;

  Time(double time, double deltaTime) : time(time), deltaTime(deltaTime) {}

  void update() { time += deltaTime; }
};

struct Sun {
  double baseEnergy;

  Sun(double baseEnergy = 1) : baseEnergy(baseEnergy) {}

  double energy(Time &time) { return sin(time.time) + baseEnergy; }
};

int main() {
  Time worldTime(0, 1);
  Sun sun;

  Map map(WORLD_SIZE_X, WORLD_SIZE_Y);

  // srand(time(0));
  // int randomSeedX = rand() % map.sizeX;
  // int randomSeedY = rand() % map.sizeY;
  // auto rootTree = std::make_shared<Tree>(randomSeedX, randomSeedY);
  // map.setMapTile(randomSeedX, randomSeedX,
  //                static_cast<std::shared_ptr<MapTile>>(rootTree));

  // std::vector<std::shared_ptr<Tree>> allTree;
  // allTree.emplace_back(rootTree);

  int test = 100;
  bool isRunning = true;
  while (isRunning && test-- >= 0) {
    worldTime.update();
    auto mapTileEnergy = sun.energy(worldTime);

    // for (auto &tree : allTree) {
    //   tree->updateMapTileEnergy(mapTileEnergy);
    // }

    std::cout << worldTime.time << std::endl;
    std::cout << mapTileEnergy << std::endl;
  }
  return 0;
}
