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
    int neighborRow = row + offset.first;
    int neighborCol = col + offset.second;

    liveNeighbors += grid.GetValue(neighborRow, neighborCol);
  }
  return liveNeighbors;
};

