#include <raylib.h>

#include <iostream>

#include "simulation.hpp"

#define TRANSPARENCY 255

int main(void) {
  Color gray = {29, 29, 29, TRANSPARENCY};

  int FPS = 12;
  const int CELL_SIZE = 4;
  const int WIN_WIDTH = 1200;
  const int WIN_HEIGHT = 800;

  InitWindow(WIN_WIDTH, WIN_HEIGHT, "Game Of Life");
  SetTargetFPS(FPS);
  Simulation simulation{WIN_WIDTH, WIN_HEIGHT, CELL_SIZE};

  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_ENTER)) {
      simulation.Start();
      SetWindowTitle("Game of Life is running!");
    }
    if (IsKeyPressed(KEY_SPACE)) {
      simulation.Stop();
      SetWindowTitle("Game of Life has stopped");
    }
    if (IsKeyPressed(KEY_UP)) {
      FPS += 2;
      SetTargetFPS(FPS);
    } else if (IsKeyPressed(KEY_DOWN)) {
      FPS -= 2;
      SetTargetFPS(FPS);
    }

    if (IsKeyPressed(KEY_R)) {
      simulation.CreateRandState();
    }
    if (IsKeyPressed(KEY_C)) {
      simulation.ClearGrid();
    }
    BeginDrawing();

    simulation.Update();
    ClearBackground(gray);
    simulation.Draw();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}

// Rule #1  If a cell is alive, it dies <2 || >3 live neighbors, else it stays
// alive Rule #2  If a cell is dead, it can come alive ONLY if it has exactly 3
// live neighbors

// #1  alive_cell + <2 live_neighbor -> dies  ||
//     alive_cell + >3 live_neighbor -> dies
// #2  dead_cell + 3 live_neighbors -> come alive
