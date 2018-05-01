/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_battle
*/

#include "rpg.h"

int battle_events(window_t *window, game_t *game)
{
	while (sfRenderWindow_pollEvent(window->window, &window->event)) {
		if (window->event.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		if (window->event.type == sfEvtMouseButtonReleased)
			CLICK_RELEASED = sfTrue;
		select_ennemy(window, game);
	}
	return (0);
}

int battle_lobby(window_t *window, game_t *game)
{
	printf("HELLO\n");
	if (battle_events(window, game) != 0
	|| manage_hit_enemy(game) != 0
	|| display_special_hit_player(window, game, NULL) != 0
	|| display_special_hit_enemy(window, game, NULL) != 0
	|| (!SPECIAL_HIT
	&& wait_for_enemy_attack(window, game, 0) != 0)
	|| manage_life_in_battle(game) != 0
	|| display_characters(window, game) != 0)
		return (84);
	return (0);
}