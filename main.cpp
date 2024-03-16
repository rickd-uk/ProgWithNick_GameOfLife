#include <raylib.h>

#define TRANSPARENCY 255

int main(void) {
  Color gray = {29, 29, 29, TRANSPARENCY};
  const int cellSize = 25;
  const int WIN_WIDTH = 750;
  const int WIN_HEIGHT = 750;
  InitWindow(WIN_WIDTH, WIN_HEIGHT, "Game Of Life");

  const int FPS = 12;
  SetTargetFPS(FPS);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(gray);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
