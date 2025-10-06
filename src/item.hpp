// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#ifndef SRC_ITEM_HPP_
#define SRC_ITEM_HPP_

#include "snake.hpp"

namespace snake {

class Item {
 public:
  enum class Type : uint8_t {
    apple = 1,
    coin = 2,
  };

  explicit Item(const Snake& snake);
  void MakeItem();

  // returns true if the snake ate the item
  bool EatCheck();

  int get_pos() const;
  Type get_type() const;

 private:
  int GenPos();
  Type GenType();

  const Snake& snake_;

  int pos_;
  Type type_;
};

}  // namespace snake
#endif  // SRC_ITEM_HPP_
