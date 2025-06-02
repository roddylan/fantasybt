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
        draft_type{draft_settings.draft_type}, is_snake{
                                                   draft_settings.is_snake} {}
  //
  DraftSettings(DraftSettings<SPORT> &&draft_settings)
      : pos_limit{draft_settings.pos_limit}, n_teams{draft_settings.n_teams},
        draft_type{draft_settings.draft_type}, is_snake{
                                                   draft_settings.is_snake} {}
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
  // default construct
  LeagueSettings() = delete;
  // value construct
  LeagueSettings(const bool &_is_keeper, const size_t &_n_teams,
                 const std::shared_ptr<DraftSettings<SPORT>> &_draft,
                 const POS_LIMIT<SPORT> &_pos_limit)
      : is_keeper(_is_keeper), n_teams(_n_teams), pos_limit(_pos_limit),
        draft(_draft) {}
  // value construct
  LeagueSettings(const bool &_is_keeper, const size_t &_n_teams,
                 const DraftSettings<SPORT> &_draft,
                 const POS_LIMIT<SPORT> &_pos_limit)
      : is_keeper(_is_keeper), n_teams(_n_teams), pos_limit(_pos_limit),
        draft(std::make_shared<DraftSettings<SPORT>>(_draft)) {}
  // copy construct
  LeagueSettings(const LeagueSettings<SPORT> &other)
      : is_keeper(other.is_keeper), n_teams(other.n_teams),
        pos_limit(other.pos_limit), draft(other.draft) {}
  // move construct
  LeagueSettings(LeagueSettings<SPORT> &&other)
      : is_keeper(other.is_keeper), n_teams(other.n_teams),
        pos_limit(std::move(other.pos_limit)), draft(std::move(other.draft)) {}
  //
  LeagueSettings<SPORT> &
  operator=(const LeagueSettings<SPORT> &other) noexcept {
    if (&other == this) {
      return *this;
    }
    this->draft = other.draft;
    this->is_keeper = other.is_keeper;
    this->n_teams = other.n_teams;
    this->pos_limit = other.pos_limit;
    return *this;
  }
  //
  LeagueSettings<SPORT> &operator=(LeagueSettings<SPORT> &&other) noexcept {
    if (&other == this) {
      return *this;
    }
    this->draft = std::move(other.draft);
    this->is_keeper = other.is_keeper;
    this->n_teams = other.n_teams;
    this->pos_limit = std::move(other.pos_limit);
    return *this;
  }
  //
  ~LeagueSettings() = default; // default destruct

  bool is_keeper;
  size_t n_teams;
  std::shared_ptr<DraftSettings<SPORT>> draft;
  POS_LIMIT<SPORT> pos_limit;
};

#endif