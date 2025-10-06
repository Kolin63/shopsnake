// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include "render.hpp"

#include <raylib.h>

#include <string>

#include "world.hpp"

constexpr int kTileSize{16};

snake::Window::Window() {
  InitWindow(600, 400, "Shop Snake");
  SetTargetFPS(60);
}

void snake::Window::Render(const Game& game) {
  BeginDrawing();
  DrawBackground();
  DrawItem(game);
  DrawSnake(game);
  DrawHUD(game);
  EndDrawing();
}

void snake::Window::DrawBackground() { ClearBackground(WHITE); }

void snake::Window::DrawSnake(const Game& game) {
  const auto& pos{game.get_snake().get_pos()};
  const int w{snake::world_size};
  const int t{kTileSize};
  for (size_t i{0}; i < pos.size(); ++i) {
    const int p{pos[i]};
    const int x1{(p % w) * t};
    const int x2{x1 + t};
    const int y1{(p / w) * t};
    const int y2{y1 + t};
    DrawTriangle({static_cast<float>(x1), static_cast<float>(y1)},
                 {static_cast<float>(x1), static_cast<float>(y2)},
                 {static_cast<float>(x2), static_cast<float>(y1)}, GREEN);
    DrawTriangle({static_cast<float>(x2), static_cast<float>(y2)},
                 {static_cast<float>(x2), static_cast<float>(y1)},
                 {static_cast<float>(x1), static_cast<float>(y2)}, GREEN);
  }
}

void snake::Window::DrawItem(const Game& game) {
  const auto& pos{game.get_item().get_pos()};
  const Color color{(game.get_item().get_type() == Item::Type::apple) ? RED
                                                                      : GOLD};
  const int w{snake::world_size};
  const int t{kTileSize};
  const int x1{(pos % w) * t};
  const int x2{x1 + t};
  const int y1{(pos / w) * t};
  const int y2{y1 + t};
  DrawTriangle({static_cast<float>(x1), static_cast<float>(y1)},
               {static_cast<float>(x1), static_cast<float>(y2)},
               {static_cast<float>(x2), static_cast<float>(y1)}, color);
  DrawTriangle({static_cast<float>(x2), static_cast<float>(y2)},
               {static_cast<float>(x2), static_cast<float>(y1)},
               {static_cast<float>(x1), static_cast<float>(y2)}, color);
}

void snake::Window::DrawHUD(const Game& game) {
  DrawText(std::to_string(game.get_gold()).c_str(), 10, 10, 30, BLACK);
}
