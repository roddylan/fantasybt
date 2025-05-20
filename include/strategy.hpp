#ifndef STRATEGY_HPP_
#define STRATEGY_HPP_
#include <functional>
#include "player.hpp"

class Strategy {
public:
  // constructors
  Strategy() = delete; // empty
  

  ~Strategy(); // destructor

private:
  std::function<void(BasePlayer, int)> draft_strategy;
  
};

#endif