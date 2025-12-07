#ifndef GAME_PREFERENCES_H
#define GAME_PREFERENCES_H

#include <string>

struct game_preferences
{
  std::string player_name;
  std::string high_scores_filename;
  unsigned int target_value;
  unsigned int max_value; 
  unsigned int nof_attempts;
};

#endif // GAME_PREFERENCES_H