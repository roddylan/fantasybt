#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include "magic_enum/magic_enum.hpp"
#include <cstddef>
#include <fmt/core.h>
#include <ostream>
#include <string>
#include <vector>

namespace Position {
enum class Football {
  QB,
  RB,
  WR,
  TE,
  STD,
  K,
  UTIL,
};

enum class Hockey {
  C,
  LW,
  RW,
  W,
  F,
  D,
  G,
  UTIL,
};
} // namespace Position

enum class PlayerStatus {
  H,    // healthy
  Q,    // questionable
  DTDO, // dtd or out
  IR,   // injured
  DNE,  // does not exist
};

// TODO: type constraint
template <typename T> class BasePlayer {
public:
  // TODO: add projected rank
  BasePlayer() : name{"None"}, rank{-1}, pos{}, status{PlayerStatus::DNE} {}
  BasePlayer(const std::string &_name, const float &_rank,
             const std::vector<T> &_pos, const PlayerStatus &_status)
      : name{_name}, rank{_rank}, pos{_pos}, status{_status} {}
  //
  BasePlayer(const BasePlayer &p)
      : name{p.name}, rank{p.rank}, pos{p.pos}, status{p.status} {}
  BasePlayer(BasePlayer &&p)
      : name{std::move(p.name)}, rank{std::move(p.rank)}, pos{std::move(p.pos)},
        status{std::move(p.status)} {}

  ~BasePlayer(){};

  BasePlayer &operator=(const BasePlayer &rhs) {
    if (&rhs == this) {
      return *this;
    }
    name = rhs.name;
    rank = rhs.rank;
    pos = rhs.pos;
    status = rhs.status;
    return *this;
  }

  BasePlayer &operator=(BasePlayer &&rhs) {
    if (&rhs != this) {
      name = std::move(rhs.name);
      rank = std::move(rhs.rank);
      pos = std::move(rhs.pos);
      status = std::move(rhs.status);
    }
    return *this;
  }
  std::vector<T> get_pos() const { return pos; }

  PlayerStatus get_status() const { return status; }
  void set_status(const PlayerStatus &_status) { status = _status; }

  std::string to_string() const {
    // name | position | rank | status
    std::string positions{};
    for (const auto &p : pos) {
      positions += std::string(magic_enum::enum_name(p)) + " ";
    }

    return fmt::format("{} | {}| Cur Rank: {:.2f} | Status: {}", name,
                       positions, rank, magic_enum::enum_name(status));
  }

  operator std::string() const { return this->to_string(); }

  template <typename U>
  friend std::ostream &operator<<(std::ostream &os,
                                  const BasePlayer<U> &player);
  //

private:
  std::string name;
  float rank;
  std::vector<T> pos;
  PlayerStatus status;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const BasePlayer<T> &player) {
  os << player.to_string();
  return os;
}

template <typename T> struct TradePackage {
  TradePackage();
  TradePackage(const TradePackage<T> &package)
      : players{package.players}, picks{package.picks} {};
  ~TradePackage();

  std::vector<BasePlayer<T>> players; // players in trade package
  std::vector<int> picks;             // draft picks in trade package
  // TODO: waiver dollars
};

template <typename T> struct Trade {
  Trade() = delete;
  Trade(TradePackage<T> _p1, TradePackage<T> _p2) : pack1{_p1}, pack2{_p2} {};
  ~Trade();

  TradePackage<T> pack1;
  TradePackage<T> pack2;
};

#endif