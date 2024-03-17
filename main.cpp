#include <raylib.h>

#include <iostream>

#include "simulation.hpp"

#define TRANSPARENCY 255

int main(void) {
  Color gray = {29, 29, 29, TRANSPARENCY};

  const int FPS = 12;
  const int CELL_SIZE = 25;
  const int WIN_WIDTH = 750;
  const int WIN_HEIGHT = 750;

  InitWindow(WIN_WIDTH, WIN_HEIGHT, "Game Of Life");
  SetTargetFPS(FPS);
  Simulation simulation{WIN_WIDTH, WIN_HEIGHT, CELL_SIZE};

  while (!WindowShouldClose()) {
    BeginDrawing();

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
