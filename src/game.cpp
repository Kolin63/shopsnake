// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include "game.hpp"

#include <raylib.h>

#include <cstddef>
#include <iostream>

#include "snake.hpp"
#include "world.hpp"

void snake::Game::Update() {
  Controls();
  UpdateSnake();
}

void snake::Game::Controls() {
  int key{GetKeyPressed()};
  while (key > 0) {
    std::cout << key << '\n';
    using enum Snake::Direction;
    switch (key) {
      case KEY_UP:
      case KEY_K:
      case KEY_W:
        if (snake_.get_dir() != down) snake_.set_dir(up);
        break;
      case KEY_RIGHT:
      case KEY_L:
      case KEY_D:
        if (snake_.get_dir() != left) snake_.set_dir(right);
        break;
      case KEY_DOWN:
      case KEY_J:
      case KEY_S:
        if (snake_.get_dir() != up) snake_.set_dir(down);
        break;
      case KEY_LEFT:
      case KEY_H:
      case KEY_A:
        if (snake_.get_dir() != right) snake_.set_dir(left);
        break;
    }
    key = GetKeyPressed();
  }
}

void snake::Game::UpdateSnake() {
  snake_.Move();
  const auto& pos{snake_.get_pos()};
  std::cout << "world size: " << snake::world_size << '\n';
  for (size_t i{0}; i < pos.size(); ++i) std::cout << pos[i] << '\n';
  std::cout << '\n';
}
