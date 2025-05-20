#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include <string>

enum PlayerPosition {
  QB,
  RB,
  WR,
  TE,
  STD,
  K,
};

class BasePlayer {
public:
  BasePlayer(const std::string &_name, const float &_rank,
             const PlayerPosition _pos)
      : name{_name}, rank{_rank}, pos{_pos} {}
  ~BasePlayer();

private:
  std::string name;
  float rank;
  PlayerPosition pos;
};

#endif