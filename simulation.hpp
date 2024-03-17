#include "grid.hpp"

class Simulation {
 public:
  Simulation(int width, int height, int cellSize)
      : grid(width, height, cellSize), tmpGrid(width, height, cellSize){};
  void Draw();
  void SetCellValue(int row, int col, int value);
  int CountLiveNeighbors(int row, int col);
  void Update();

 private:
  Grid grid;
  Grid tmpGrid;
};
