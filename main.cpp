#include <raylib.h>

#include "grid.hpp"

#define TRANSPARENCY 255

int main(void) {
  Color gray = {29, 29, 29, TRANSPARENCY};

  const int FPS = 12;
  const int CELL_SIZE = 25;
  const int WIN_WIDTH = 750;
  const int WIN_HEIGHT = 750;

  InitWindow(WIN_WIDTH, WIN_HEIGHT, "Game Of Life");
  SetTargetFPS(FPS);

  Grid grid(WIN_WIDTH, WIN_HEIGHT, CELL_SIZE);
  grid.SetValue(0, 0, 1);
  grid.SetValue(2, 1, 1);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(gray);
    grid.Draw();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
