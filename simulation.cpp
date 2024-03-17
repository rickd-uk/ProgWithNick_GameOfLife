#include "simulation.hpp"

#include <utility>
#include <vector>

void Simulation::Draw() { grid.Draw(); }

void Simulation::SetCellValue(int row, int col, int value) {
  grid.SetValue(row, col, value);
}

int Simulation::CountLiveNeighbors(int row, int col) {
  int liveNeighbors = 0;
  std::vector<std::pair<int, int>> neighborOffsets = {
      {-1, 0},   // above
      {1, 0},    // below
      {0, -1},   // left
      {0, 1},    // right
      {-1, -1},  // upper left
      {-1, 1},   // upper right
      {1, -1},   // lower left
      {1, 1},    // lower right
  };
  for (const auto& offset : neighborOffsets) {
    int neighborRow =
        (row + offset.first + grid.GetNumRows()) % grid.GetNumRows();
    int neighborCol =
        (col + offset.second + grid.GetNumCols()) % grid.GetNumCols();

    liveNeighbors += grid.GetValue(neighborRow, neighborCol);
  }
  return liveNeighbors;
};

void Simulation::Update() {
  if (IsRunning()) {
    for (int row = 0; row < grid.GetNumRows(); row++) {
      for (int col = 0; col < grid.GetNumCols(); col++) {
        int liveNeighbors = CountLiveNeighbors(row, col);
        int cellValue = grid.GetValue(row, col);

        if (cellValue == 1) {
          if (liveNeighbors > 3 || liveNeighbors < 2) {
            tmpGrid.SetValue(row, col, 0);
          } else {
            tmpGrid.SetValue(row, col, 1);
          }
        } else {
          if (liveNeighbors == 3) {
            tmpGrid.SetValue(row, col, 1);
          } else {
            tmpGrid.SetValue(row, col, 0);
          }
        }
      }
    }
    grid = tmpGrid;
  }
}

void Simulation::ClearGrid() {
  if (!IsRunning()) {
    grid.Clear();
  }
}

void Simulation::CreateRandState() {
  if (!IsRunning()) {
    grid.FillRand();
  }
}
