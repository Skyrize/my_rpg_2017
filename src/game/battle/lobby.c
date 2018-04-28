/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_battle
*/

#include "rpg.h"

///mettre ici les events relatifs à un combat. les events généraux de type click sur boutons sont déjà géré.

int battle_events(window_t *window, game_t *game)
{
	while (sfRenderWindow_pollEvent(window->window, &window->event)) {
		if (window->event.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		if (window->event.type == sfEvtMouseButtonReleased)
			CLICK_RELEASED = sfTrue;
	}
	return (0);
}

int battle_lobby(window_t *window, game_t *game)
{
	if (battle_events(window, game) != 0
	|| manage_hit_enemy(game) != 0
	|| manage_notif_right(game, "Tu est pd") != 0
	|| manage_notif_left(game, "Tu est pd") != 0)
		return (84);
	return (0);
}