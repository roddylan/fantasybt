// arb_strat.hpp
// simple strategy
#ifndef FBT_ARB_STRAT_HPP_
#define FBT_ARB_STRAT_HPP_
#include "strategy.hpp"
#include <functional>


class ArbStrategy : public Strategy {
public:
  ~ArbStrategy();

  void draft_strategy(const BasePlayer<T_FOOTBALL> &, const int &) override;
  void roster_strategy() override;
  void trade_strategy(const BasePlayer<T_FOOTBALL> &p1, const BasePlayer<T_FOOTBALL> &p2) override;

private:
};




#endif