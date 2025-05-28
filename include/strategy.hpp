#ifndef FBT_STRATEGY_HPP_
#define FBT_STRATEGY_HPP_
#include "player.hpp"
#include "roster.hpp"
#include <algorithm>
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

/**
 * @class Strategy
 * @brief Strategy base class
 * 
 */
class Strategy {
public:
  // constructors
  Strategy() = delete; // empty
  Strategy(const std::unordered_map<T_FOOTBALL, size_t> &counts,
           const int &roster_sz)
      : roster{counts, roster_sz} {}
  Strategy(const Strategy &strat)
      : roster{strat.roster}, win{strat.win}, loss{strat.loss} {}

  virtual ~Strategy(); // destructor

  Strategy &operator=(const Strategy &rhs) {
    if (&rhs == this) { return *this; }
    this->roster = rhs.roster;
    this->win = rhs.win;
    this->loss = rhs.loss;
    return *this;
  }

  virtual void draft_strategy(const BasePlayer<T_FOOTBALL> &, const int &){};

  virtual void roster_strategy(){};

  virtual void trade_strategy(const BasePlayer<T_FOOTBALL> &p1,
                              const BasePlayer<T_FOOTBALL> &p2){};

  void send_trade();
  void receive_trade();

  void draft();

  void update_performance(const bool &_win) {
    win += _win;
    loss += !_win;
  }

  void run(const bool &is_draft, const size_t &year, const size_t &week, const size_t &day) {
    if (is_draft) {
      // todo: finish

      return;
    }
  } // run strategy

private:
  size_t win;
  size_t loss;
  
  Roster<T_FOOTBALL> roster;
};



#endif