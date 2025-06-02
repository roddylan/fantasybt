#ifndef FBT_STATE_HPP_
#define FBT_STATE_HPP_
#include "player.hpp"
#include "settings.hpp"
#include <memory>
#include <vector>

// TODO: convert using baseplayer to just holding player ids

template <typename SPORT> class TeamState {
public:
  TeamState() : roster{}, total_pts{} {}
  // value construct
  TeamState(const std::vector<std::shared_ptr<BasePlayer<SPORT>>> &_roster,
            const size_t &_total_pts)
      : roster(_roster), total_pts(_total_pts) {}
  // copy construct
  TeamState(const TeamState<SPORT> &other) : roster(other.roster), total_pts{other.total_pts} {}
  // move construct
  TeamState(TeamState<SPORT> &&other) : roster(std::move(other.roster)), total_pts{other.total_pts} {}
  // copy assign
  TeamState& operator=(const TeamState<SPORT> &other) {
    if (&other == this) { return *this; }
    this->total_pts = other.total_pts;
    this->roster = other.roster;
    return *this;
  }
  // move assign
  TeamState& operator=(TeamState<SPORT> &&other) {
    if (&other == this) { return *this; }
    this->total_pts = other.total_pts;
    this->roster = std::move(other.roster);
    return *this;
  }

private:
  std::vector<std::shared_ptr<BasePlayer<SPORT>>> roster;
  size_t total_pts;
};
// hold roster, total pts

template <typename SPORT> class LeagueState {
public:
private:
  std::vector<std::shared_ptr<TeamState<SPORT>>> team_states;
  std::unique_ptr<LeagueSettings<SPORT>> settings;
  std::vector<std::unique_ptr<BasePlayer<SPORT>>> free_agency;
};

#endif