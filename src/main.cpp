// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <raylib.h>

#include "game.hpp"
#include "render.hpp"
#include "world.hpp"

int main() {
  snake::world_size = 20;
  snake::Window window{};
  snake::Game game{};

  while (!WindowShouldClose()) {
    if (game.get_alive()) game.Update();
    window.Render(game);
  }

  CloseWindow();
  return 0;
}
