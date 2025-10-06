// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#ifndef SRC_SNAKE_HPP_
#define SRC_SNAKE_HPP_

#include <vector>

namespace snake {

class Snake {
 public:
  enum class Direction { up, right, down, left };

  Snake() : pos{5, 4, 3}, dir{Direction::right} { pos.reserve(10); }

  // makes the snake one longer
  void Increase();

  // makes the snake one shorter
  // doesn't do length checks
  void Decrease();

  // moves the snake based on direction
  // returns false if the snake collides
  bool Move();

  const std::vector<int>& get_pos();

 private:
  std::vector<int> pos;  // pos[0] is head
  Direction dir;         // only refers to head tile
};

}  // namespace snake

#endif  // SRC_SNAKE_HPP_
