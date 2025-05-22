#include <cassert>
#include <iostream>
#include "player.hpp"


int main() {
  BasePlayer<Position::Football> temp{
    "CeeDee Lamb",
    1,
    std::vector<Position::Football> {Position::Football::WR},
    PlayerStatus::H
  };
  

  std::cout << temp.to_string();


  return 0;
}