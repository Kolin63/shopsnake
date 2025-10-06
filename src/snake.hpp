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

  // makes the snake one longer
  void Increase();

  // makes the snake one shorter
  // doesn't do length checks
  void Decrease();

  // moves the snake based on direction
  // returns false if the snake collides
  bool Move();

  // adds action to queue
  void Queue(Direction dir);

  Direction get_dir() const;
  void set_dir(Direction dir);

  const std::vector<int>& get_pos() const;

 private:
  Direction OppositeDir(Direction dir);

  std::vector<int> pos_{5, 4, 3};    // pos[0] is head
  Direction dir_{Direction::right};  // only refers to head tile
  std::vector<Direction> queue_{};
};

}  // namespace snake

#endif  // SRC_SNAKE_HPP_
