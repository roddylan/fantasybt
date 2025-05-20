#ifndef ROSTER_HPP_
#define ROSTER_HPP_
#include "player.hpp"
#include <vector>
#include <unordered_map>

template<typename T>
class AvailablePlayers {

};


template<typename T>
struct Roster {


  std::unordered_map<T, size_t> avail_pos;
  std::vector<T> players;
  
  
};


#endif