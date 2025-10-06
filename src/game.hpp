// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#include "snake.hpp"

namespace snake {

class Game {
 public:
  Game() : snake_{} {};

  void Update();

 private:
  void Controls();
  void UpdateSnake();

  Snake snake_;
};

}  // namespace snake

#endif  // SRC_GAME_H_
