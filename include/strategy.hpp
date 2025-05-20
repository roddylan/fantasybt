#ifndef STRATEGY_HPP_
#define STRATEGY_HPP_
#include "player.hpp"
#include "roster.hpp"
#include <functional>
#include <unordered_map>

// TODO: template
typedef Position::Football T_FOOTBALL;

const auto empty_draft_strategy = []<typename T>(const T &player,
                                                 const int &pick) {};
// const auto empty_trade_strategy = []<typename T>(const T &player1, const T
// &player2) {};
const auto empty_roster_strategy = []<typename T>(const T &player,
                                                  const int &pick) {};

// template <typename T>
class Strategy {
public:
  // constructors
  Strategy(); // empty
  Strategy(const std::unordered_map<T_FOOTBALL, size_t> &counts, const int &roster_sz);

  virtual ~Strategy(); // destructor

  virtual void draft_strategy(BasePlayer<T_FOOTBALL>, int) {};

  virtual void roster_strategy() {};

  virtual void trade_strategy(BasePlayer<T_FOOTBALL> p1, BasePlayer<T_FOOTBALL> p2) {};

  void send_trade();
  void receive_trade();

  void draft();

  void update_performance(const bool &_win) {
    win += _win;
    loss += !_win;
  }

  void run(bool draft, size_t year, size_t week, size_t day); // run strategy

private:
  Roster<T_FOOTBALL> roster;

  size_t win;
  size_t loss;
};

#endif