// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#ifndef SRC_RENDER_HPP_
#define SRC_RENDER_HPP_

#include "game.hpp"

namespace snake {

class Window {
 public:
  Window();

  void Render(const Game& game);

 private:
  void DrawBackground();
  void DrawSnake(const Game& game);
  void DrawItem(const Game& game);
  void DrawHUD(const Game& game);
};

}  // namespace snake

#endif  // SRC_RENDER_HPP_
