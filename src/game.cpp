// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include "game.hpp"

#include <raylib.h>

#include <cstddef>
#include <iostream>

#include "snake.hpp"
#include "world.hpp"

constexpr int kUPS{6};

void snake::Game::Update() {
  Controls();
  delta_ += GetFrameTime();
  if (delta_ >= 1.0 / kUPS) {
    delta_ -= (1.0 / kUPS);
    UpdateSnake();
    if (item_.EatCheck()) {
      if (item_.get_type() == Item::Type::apple) {
        snake_.Increase();
      } else {
        gold_++;
      }
      item_.MakeItem();
    }
  }
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
  if (!snake_.Move()) alive_ = false;
  const auto& pos{snake_.get_pos()};
  std::cout << "world size: " << snake::world_size << '\n';
  for (size_t i{0}; i < pos.size(); ++i) std::cout << pos[i] << '\n';
  std::cout << '\n';
}

const snake::Snake& snake::Game::get_snake() const { return snake_; }
const snake::Item& snake::Game::get_item() const { return item_; }

bool snake::Game::get_alive() const { return alive_; }

int snake::Game::get_gold() const { return gold_; }
void snake::Game::set_gold(int gold) { gold_ = gold; }
