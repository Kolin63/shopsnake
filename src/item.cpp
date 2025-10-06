// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include "item.hpp"

#include <cstddef>

#include "random.hpp"
#include "world.hpp"

snake::Item::Item(const Snake& snake) : snake_{snake} { MakeItem(); }

void snake::Item::MakeItem() {
  pos_ = GenPos();
  type_ = GenType();
}

bool snake::Item::EatCheck() { return snake_.get_pos()[0] == pos_; }

int snake::Item::GenPos() {
  const int max{snake::world_size * snake::world_size - 1};
  const auto& pos{snake_.get_pos()};
  while (true) {
  next_gen:
    int x{random::get(0, max)};
    for (size_t i{0}; i < pos.size(); ++i) {
      if (pos[i] == x) goto next_gen;
    }
    return x;
  }
}

snake::Item::Type snake::Item::GenType() {
  return static_cast<Type>(random::get(0, 1));
}

int snake::Item::get_pos() const { return pos_; }
snake::Item::Type snake::Item::get_type() const { return type_; }
