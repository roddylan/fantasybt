#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include <cstddef>
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
  Q,    // questionable
  DTDO, // dtd or out
  IR,   // injured
};

// TODO: type constraint
template <typename T> class BasePlayer {
public:
  BasePlayer(const std::string &_name, const float &_rank,
             const std::vector<T> &_pos, const PlayerStatus &_status)
      : name{_name}, rank{_rank}, pos{_pos}, status{_status} {}

  ~BasePlayer();

private:
  std::string name;
  float rank;
  std::vector<T> pos;
  PlayerStatus status;
};

template<typename T>
struct TradePackage {
  TradePackage();
  TradePackage(const TradePackage<T> &package) : players{package.players}, picks{package.picks} {};
  ~TradePackage();

  std::vector<BasePlayer<T>> players; // players in trade package
  std::vector<int> picks;             // draft picks in trade package
  // TODO: waiver dollars
};

template<typename T>
struct Trade {
  Trade() = delete;
  Trade(TradePackage<T> _p1, TradePackage<T> _p2) : pack1{_p1}, pack2{_p2} {};
  ~Trade();

  TradePackage<T> pack1;
  TradePackage<T> pack2;
};


#endif