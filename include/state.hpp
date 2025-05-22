#ifndef FBT_STATE_HPP_
#define FBT_STATE_HPP_
#include "player.hpp"
#include "settings.hpp"
#include <memory>
#include <vector>


template <typename SPORT>
class TeamState {

};


template <typename SPORT>
class LeagueState {
public:

private:
  std::vector<std::unique_ptr<TeamState<SPORT>>> team_states;
  std::unique_ptr<LeagueSettings<SPORT>> settings;
  std::vector<std::unique_ptr<BasePlayer<SPORT>>> free_agency;
};



#endif