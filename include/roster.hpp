#ifndef ROSTER_HPP_
#define ROSTER_HPP_
#include "player.hpp"
#include <unordered_map>
#include <vector>
#include <memory>

template <typename T> class AvailablePlayers {};

template <typename T> struct Roster {
  Roster() = delete;
  Roster(const std::unordered_map<T, size_t> &_avail_pos,
         const std::vector<T> &_players)
      : avail_pos{_avail_pos}, players{_players} {}
  //

  Roster(const std::unordered_map<T, size_t> &_avail_pos, const size_t &_sz)
      : avail_pos{_avail_pos}, players(_sz) {}
  //

  std::unordered_map<T, size_t> avail_pos;
  std::vector<std::shared_ptr<BasePlayer<T>>> players;
};

#endif