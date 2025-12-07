#ifndef HIGH_SCORES_H
#define HIGH_SCORES_H

struct game_preferences;

void
process_high_score(const game_preferences &game_prefs);

void
high_scores_output(const game_preferences &game_prefs);

void
high_scores_output_filtered_min(const game_preferences &game_prefs);

#endif // HIGH_SCORES_H