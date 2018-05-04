/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_battle
*/

#include "rpg.h"

int battle_events(window_t *window, game_t *game)
{
	if (window->event.type == sfEvtClosed)
		sfRenderWindow_close(window->window);
	if (window->event.type == sfEvtMouseButtonReleased)
		CLICK_RELEASED = sfTrue;
	select_ennemy(window, game);
	return (0);
}

int battle_lobby(window_t *window, game_t *game)
{
	get_time(&window->clocker);
	if (battle_events(window, game) != 0
	|| manage_hit_enemy(game, 0, 0) != 0
	|| (SPECIAL_HIT && display_special_hit_player(window, game, NULL) != 0)
	|| (SPECIAL_HIT && display_special_hit_enemy(window, game, NULL) != 0)
	|| (!SPECIAL_HIT && wait_for_enemy_attack(window, game, 0) != 0)
	|| manage_life_in_battle(game) != 0
	|| display_characters(window, game) != 0)
		return (84);
	if (!SPECIAL_HIT && window->clocker.seconds >= 3
	&& game->battle.win) {
		if (battle_end_screen(game, "WIN") == 84)
			return (84);
	} else if (!SPECIAL_HIT && window->clocker.seconds >= 3
	&& game->battle.lose) {
		if (battle_end_screen(game, "LOSE") == 84)
			return (84);
	}
	return (0);
}