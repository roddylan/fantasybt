#include <iostream>
#include "player.hpp"
#include <string>
#include <format>

template<typename T>
std::ostream &operator<<(std::ostream &os, const BasePlayer<T> &player) {
  os << player.to_string();
  return os;
}