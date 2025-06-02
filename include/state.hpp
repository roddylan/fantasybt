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
            const long &_total_pts)
      : roster(_roster), total_pts(_total_pts) {}
  // copy construct
  TeamState(const TeamState<SPORT> &other) : roster(other.roster), total_pts{other.total_pts} {}
  // move construct
  TeamState(TeamState<SPORT> &&other) : roster(std::move(other.roster)), total_pts{other.total_pts} {}
  // copy assign
  TeamState<SPORT>& operator=(const TeamState<SPORT> &other) {
    if (&other == this) { return *this; }
    this->total_pts = other.total_pts;
    this->roster = other.roster;
    return *this;
  }
  // move assign
  TeamState<SPORT>& operator=(TeamState<SPORT> &&other) {
    if (&other == this) { return *this; }
    this->total_pts = other.total_pts;
    this->roster = std::move(other.roster);
    return *this;
  }

  bool operator<(const TeamState<SPORT> &other) const noexcept {
    return this->total_pts < other.total_pts;
  }
  
  bool operator>(const TeamState<SPORT> &other) const noexcept {
    return this->total_pts > other.total_pts;
  }
  
  bool operator==(const TeamState<SPORT> &other) const noexcept {
    return this->total_pts == other.total_pts;
  }
  // TODO addition ops
  void set_total_pts(const long &pts) {
    total_pts = pts;
  }

  long get_total_pts() {
    return total_pts;
  }

  long update_total_pts(const long &add_pts) {
    total_pts += add_pts;
    return total_pts;
  }

  
private:
  std::vector<std::shared_ptr<BasePlayer<SPORT>>> roster;
  long total_pts;
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