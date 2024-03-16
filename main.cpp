#include <raylib.h>

#define TRANSPARENCY 255

int main(void) {
  Color gray = {29, 29, 29, TRANSPARENCY};
  InitWindow(800, 600, "Game Of Life");

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
