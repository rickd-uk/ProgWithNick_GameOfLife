#include "grid.hpp"

class Simulation {
 public:
  Simulation(int width, int height, int cellSize)
      : grid(width, height, cellSize),
        tmpGrid(width, height, cellSize),
        running(false){
            /* grid.FillRand(); */
        };
  void Draw();
  void SetCellValue(int row, int col, int value);
  int CountLiveNeighbors(int row, int col);
  void Update();
  bool IsRunning() { return running; }
  void Start() { running = true; }
  void Stop() { running = false; }
  void ClearGrid();
  void CreateRandState();

 private:
  Grid grid;
  Grid tmpGrid;
  bool running;
};
