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
    game.Update();
    window.Render(game);
    if (game.get_alive() == false) break;
  }

  CloseWindow();
  return 0;
}
