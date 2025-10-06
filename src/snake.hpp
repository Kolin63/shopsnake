// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#ifndef SRC_SNAKE_HPP_
#define SRC_SNAKE_HPP_

#include <cstdint>
#include <vector>

namespace snake {

class Snake {
 public:
  enum class Direction : uint8_t { up, right, down, left };

  Snake() : pos_{5, 4, 3}, dir_{Direction::right} { pos_.reserve(10); };

  // makes the snake one longer
  void Increase();

  // makes the snake one shorter
  // doesn't do length checks
  void Decrease();

  // moves the snake based on direction
  // returns false if the snake collides
  bool Move();

  Direction get_dir();
  void set_dir(Direction dir);

  const std::vector<int>& get_pos();

 private:
  std::vector<int> pos_;  // pos[0] is head
  Direction dir_;         // only refers to head tile
};

}  // namespace snake

#endif  // SRC_SNAKE_HPP_
