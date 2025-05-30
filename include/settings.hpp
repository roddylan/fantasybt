#ifndef FBT_SETTINGS_HPP_
#define FBT_SETTINGS_HPP_
#include <memory>
#include <unordered_map>
#include <vector>

// TODO: constraints

enum class DraftType {
  STANDARD,
  SAL_CAP,
};

template <typename T> using POS_LIMIT = std::unordered_map<T, size_t>;

template <typename SPORT> struct DraftSettings {
  DraftSettings() = delete;
  DraftSettings(const POS_LIMIT<SPORT> &_lim, const size_t &_n_teams,
                const DraftType &_draft_type, const bool &_is_snake)
      : pos_limit{_lim}, n_teams{_n_teams},
        draft_type{_draft_type}, is_snake{_is_snake} {}
  //
  DraftSettings(const DraftSettings<SPORT> &draft_settings)
      : pos_limit{draft_settings.pos_limit}, n_teams{draft_settings.n_teams},
        draft_type{draft_settings.draft_type}, is_snake{draft_settings.is_snake} {}
  //
  DraftSettings(DraftSettings<SPORT> &&draft_settings)
      : pos_limit{draft_settings.pos_limit}, n_teams{draft_settings.n_teams},
        draft_type{draft_settings.draft_type}, is_snake{draft_settings.is_snake} {}
  //
  ~DraftSettings() = default;

  DraftSettings<SPORT> &operator=(const DraftSettings<SPORT> &rhs) noexcept {
    if (&rhs == this) {
      return *this;
    }
    this->pos_limit = rhs.pos_limit;
    this->n_teams = rhs.n_teams;
    this->draft_type = rhs.draft_type;
    this->is_snake = rhs.is_snake;
    return *this;
  }

  DraftSettings<SPORT> &operator=(DraftSettings<SPORT> &&rhs) noexcept {
    if (&rhs == this) {
      return *this;
    }
    this->pos_limit = rhs.pos_limit;
    this->n_teams = rhs.n_teams;
    this->draft_type = rhs.draft_type;
    this->is_snake = rhs.is_snake;
    return *this;
  }

  POS_LIMIT<SPORT> pos_limit;
  const size_t n_teams;
  const DraftType draft_type;
  const bool is_snake;
};

template <typename SPORT> struct LeagueSettings {
  size_t n_teams;

  POS_LIMIT<SPORT> pos_limit;
  std::unique_ptr<DraftSettings<SPORT>> settings;
  const bool is_keeper;
};

#endif