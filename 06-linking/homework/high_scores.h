#ifndef HIGH_SCORES_H
#define HIGH_SCORES_H

struct game_preferences;

void
process_high_score(game_preferences &game_prefs);

void
high_scores_ouput(game_preferences &game_prefs);

#endif // HIGH_SCORES_H