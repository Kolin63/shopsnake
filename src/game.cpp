// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include "game.hpp"

#include <iostream>

#include "raylib.h"

void snake::Game::Update() {
  Controls();
  UpdateSnake();
}

void snake::Game::Controls() {
  int key{GetKeyPressed()};
  while (key > 0) {
    std::cout << key << '\n';
    key = GetKeyPressed();
  }
}

void snake::Game::UpdateSnake() {
  // snake_.Move();
  return;
}
