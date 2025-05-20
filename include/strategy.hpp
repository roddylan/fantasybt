#ifndef STRATEGY_HPP_
#define STRATEGY_HPP_
#include <functional>
#include "player.hpp"
#include "roster.hpp"

// TODO: template
typedef Position::Football T_FOOTBALL;


const auto empty_draft_strategy = []<typename T>(const T &player, const int &pick) {};
// const auto empty_trade_strategy = []<typename T>(const T &player1, const T &player2) {};
const auto empty_roster_strategy = []<typename T>(const T &player, const int &pick) {};


class Strategy {
public:
  // constructors
  Strategy() = delete; // empty
  

  ~Strategy(); // destructor

  void send_trade();
  

private:
  std::function<void(BasePlayer<T_FOOTBALL>, int)> draft_strategy; // void(player, draft pick)
  std::function<BasePlayer<T_FOOTBALL>(BasePlayer<T_FOOTBALL>, BasePlayer<T_FOOTBALL>)> trade_strategy;
  std::function<void(Roster<T_FOOTBALL>)> roster_strategy;

  Roster<T_FOOTBALL> roster;



};

#endif