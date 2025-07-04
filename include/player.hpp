#ifndef FBT_PLAYER_HPP_
#define FBT_PLAYER_HPP_
#include "magic_enum/magic_enum.hpp"
#include <cstddef>
#include <fmt/core.h>
#include <ostream>
#include <string>
#include <vector>

using PID = std::string;

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
  BasePlayer()
      : name{"None"}, rank{-1}, pos{}, status{PlayerStatus::DNE}, player_id{} {}
  BasePlayer(const std::string &_name, const float &_rank,
             const std::vector<T> &_pos, const PlayerStatus &_status,
             const PID &_pid)
      : name{_name}, rank{_rank}, pos{_pos}, status{_status}, player_id{_pid} {}
  //
  BasePlayer(const BasePlayer &p)
      : name{p.name}, rank{p.rank}, pos{p.pos}, status{p.status},
        player_id{p.player_id} {}
  BasePlayer(BasePlayer &&p)
      : name{std::move(p.name)}, rank{std::move(p.rank)}, pos{std::move(p.pos)},
        status{std::move(p.status)}, player_id{std::move(p.player_id)} {}

  ~BasePlayer() = default;

  BasePlayer &operator=(const BasePlayer &rhs) noexcept {
    if (&rhs == this) {
      return *this;
    }
    name = rhs.name;
    rank = rhs.rank;
    pos = rhs.pos;
    status = rhs.status;
    player_id = rhs.player_id;
    return *this;
  }

  BasePlayer &operator=(BasePlayer &&rhs) noexcept {
    if (&rhs != this) {
      name = std::move(rhs.name);
      rank = std::move(rhs.rank);
      pos = std::move(rhs.pos);
      status = std::move(rhs.status);
      player_id = std::move(rhs.player_id);
    }
    return *this;
  }
  std::vector<T> get_pos() const noexcept { return pos; }

  PlayerStatus get_status() const noexcept { return status; }
  void set_status(const PlayerStatus &_status) { status = _status; }

  std::string to_string() const noexcept {
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
  PID player_id;
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