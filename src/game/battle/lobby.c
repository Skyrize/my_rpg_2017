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
	(void)window;
	(void)game;
	return (0);
}

int battle_lobby(window_t *window, game_t *game)
{

	if (battle_events(window, game) != 0)
		return (84);
	return (0);
}