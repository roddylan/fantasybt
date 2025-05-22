#ifndef FBT_ROSTER_HPP_
#define FBT_ROSTER_HPP_
#include "player.hpp"
#include <algorithm>
#include <memory>
#include <unordered_map>
#include <vector>

template <typename T> class AvailablePlayers {};

template <typename T> struct Roster {
  Roster() = delete;
  Roster(const Roster &roster)
      : avail_pos(roster.avail_pos), players(roster.players) {}
  //
  Roster(const std::unordered_map<T, size_t> &_avail_pos,
         const std::vector<std::shared_ptr<BasePlayer<T>>> &_players)
      : avail_pos{_avail_pos}, players{_players} {}
  //
  Roster(const std::unordered_map<T, size_t> &_avail_pos, const size_t &_sz)
      : avail_pos{_avail_pos}, players(_sz) {}
  //
  Roster(Roster &&roster)
      : avail_pos{std::move(roster.avail_pos)}, players{std::move(
                                                    roster.players)} {}
  //

  Roster &operator=(const Roster &rhs) {
    if (&rhs == this) {
      return *this;
    }
    this->avail_pos = rhs.avail_pos;
    this->players = rhs.players;
    return *this;
  }

  Roster &operator=(Roster &&rhs) {
    if (this != &rhs) {
      avail_pos = std::move(rhs.avail_pos);
      players = std::move(rhs.players);
    }
    return *this;
  }

  std::unordered_map<T, size_t> avail_pos;
  std::vector<std::shared_ptr<BasePlayer<T>>> players;
};

#endif