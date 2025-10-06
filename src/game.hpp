// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#ifndef SRC_GAME_HPP_
#define SRC_GAME_HPP_

#include "snake.hpp"

namespace snake {

class Game {
 public:
  void Update();

  const Snake& get_snake() const;

 private:
  void Controls();
  void UpdateSnake();

  Snake snake_{};

  float delta_{};
};

}  // namespace snake

#endif  // SRC_GAME_HPP_
