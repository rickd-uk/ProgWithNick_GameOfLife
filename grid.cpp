#include "grid.hpp"

#include <raylib.h>

void Grid::Draw() {
  const int gridCellSize = (cellSize - 1);
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      Color color =
          cells[row][col] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};
      DrawRectangle(col * cellSize, row * cellSize, gridCellSize, gridCellSize,
                    color);
    }
  }
}

void Grid::SetValue(int row, int col, int value) {
  if (IsWithinBounds(row, col)) {
    cells[row][col] = value;
  }
}

int Grid::GetValue(int row, int col) {
  if (IsWithinBounds(row, col)) {
    return cells[row][col];
  }
  return 0;
}

bool Grid::IsWithinBounds(int row, int col) {
  if (row >= 0 && row < rows && col >= 0 && col < cols) {
    return true;
  }
  return false;
}
