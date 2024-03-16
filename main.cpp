#include <raylib.h>

int main(void) {
  InitWindow(800, 600, "Game Of Life");

  const int FPS = 12;
  SetTargetFPS(FPS);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
