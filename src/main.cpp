// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <raylib.h>

int main() {
  InitWindow(600, 400, "Shop Snake");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(WHITE);
    DrawTriangle({0, 0}, {0, 16}, {16, 0}, BLACK);
    DrawTriangle({16, 16}, {16, 0}, {0, 16}, BLACK);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
