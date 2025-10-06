// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include "snake.hpp"

#include <cstddef>
#include <vector>

#include "world.hpp"

void snake::Snake::Increase() { pos_.push_back(pos_[pos_.size() - 1]); }

void snake::Snake::Decrease() { pos_.pop_back(); }

bool snake::Snake::Move() {
  // update everything after the head
  for (size_t i{pos_.size() - 1}; i >= 1; --i) {
    pos_[i] = pos_[i - 1];
  }
  // update the head
  switch (dir_) {
    case Direction::up: {
      pos_[0] -= world_size;
      break;
    }
    case Direction::right: {
      pos_[0] += 1;
      break;
    }
    case Direction::down: {
      pos_[0] += world_size;
      break;
    }
    case Direction::left: {
      pos_[0] -= 1;
      break;
    }
  }

  // TODO(kolin63): collision check
  return true;
}

snake::Snake::Direction snake::Snake::get_dir() const { return dir_; }
void snake::Snake::set_dir(Direction dir) { dir_ = dir; }

const std::vector<int>& snake::Snake::get_pos() const { return pos_; }
