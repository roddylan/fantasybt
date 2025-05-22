#include "player.hpp"
#include <cassert>
#include <iostream>

int main() {
  BasePlayer<Position::Football> temp{
      "CeeDee Lamb", 1, std::vector<Position::Football>{Position::Football::WR},
      PlayerStatus::H};
  std::cout << temp << std::endl;
  std::string base{"CeeDee Lamb | WR | Cur Rank: 1.00 | Status: H"};
  assert(base == temp.to_string());
  assert(base == std::string{temp});
  
  assert(temp.get_status() == PlayerStatus::H);
  temp.set_status(PlayerStatus::DTDO);
  assert(temp.get_status() == PlayerStatus::DTDO);


  return 0;
}