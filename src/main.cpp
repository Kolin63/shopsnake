// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <raylib.h>

int main() {
  InitWindow(600, 400, "Hello");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(WHITE);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
