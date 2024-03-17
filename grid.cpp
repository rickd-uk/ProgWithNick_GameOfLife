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

void Grid::FillRand() {
  for (int row = 0; row < rows; row++) {
    for (int col = 1; col < cols; col++) {
      int randVal = GetRandomValue(0, 4);
      cells[row][col] = (randVal == 4) ? 1 : 0;
    }
  }
}

void Grid::Clear() {
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      cells[row][col] = 0;
    }
  }
}
