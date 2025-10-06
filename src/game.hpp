// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#ifndef SRC_GAME_HPP_
#define SRC_GAME_HPP_

#include "item.hpp"
#include "snake.hpp"

namespace snake {

class Game {
 public:
  void Update();

  const Snake& get_snake() const;
  const Item& get_item() const;

  int get_gold() const;
  void set_gold(int gold);

 private:
  void Controls();
  void UpdateSnake();

  Snake snake_{};
  Item item_{snake_};

  float delta_{};

  int gold_{};
};

}  // namespace snake

#endif  // SRC_GAME_HPP_
