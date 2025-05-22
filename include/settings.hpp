#ifndef FBT_SETTINGS_HPP_
#define FBT_SETTINGS_HPP_
#include <memory>
#include <vector>
#include <unordered_map>

// TODO: constraints

enum class DraftType {
  STANDARD,
  SAL_CAP,
};

template <typename T>
using POS_LIMIT = std::unordered_map<T, size_t>;

template <typename SPORT>
struct DraftSettings {
  DraftSettings() = delete;
  

  const POS_LIMIT<SPORT> pos_limit;
  const size_t n_teams;
  const DraftType draft_type;
  const bool is_snake;
};


template <typename SPORT>
struct LeagueSettings {
  size_t n_teams;
  
  POS_LIMIT<SPORT> pos_limit;
  std::unique_ptr<DraftSettings<SPORT>> settings;
  const bool is_keeper;
  
};


#endif