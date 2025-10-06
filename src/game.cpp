// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include "game.hpp"

#include <raylib.h>

#include "snake.hpp"

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
    using enum Snake::Direction;
    switch (key) {
      case KEY_UP:
      case KEY_K:
      case KEY_W:
        snake_.Queue(up);
        break;
      case KEY_RIGHT:
      case KEY_L:
      case KEY_D:
        snake_.Queue(right);
        break;
      case KEY_DOWN:
      case KEY_J:
      case KEY_S:
        snake_.Queue(down);
        break;
      case KEY_LEFT:
      case KEY_H:
      case KEY_A:
        snake_.Queue(left);
        break;
      case KEY_SPACE:
        Shop();
        break;
    }
    key = GetKeyPressed();
  }
}

void snake::Game::UpdateSnake() {
  if (!snake_.Move()) alive_ = false;
}

void snake::Game::Shop() {
  constexpr int kPrice{3};
  if (gold_ < kPrice || snake_.get_pos().size() <= 3) return;
  gold_ -= kPrice;
  snake_.Decrease();
}

const snake::Snake& snake::Game::get_snake() const { return snake_; }
const snake::Item& snake::Game::get_item() const { return item_; }

bool snake::Game::get_alive() const { return alive_; }

int snake::Game::get_gold() const { return gold_; }
void snake::Game::set_gold(int gold) { gold_ = gold; }
