/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** player_anim.c created: 04/04/18 19:18
*/

#include <rpg.h>

void anim_player(my_w_t *window)
{
	if (!(window && my_strcmp(window->current->key, "GAME") != 0))
		return;
	//if (!(window->game.player))
	//	return;
	time_animation(window->game.player.character, 0.02, window);
}