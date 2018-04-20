/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** is_player_moving.c created: 19/04/18
*/

#include <rpg.h>

bool is_player_moving(my_w_t *window)
{
	if (strcmp(window->current->key, "GAME") != 0)
		return (false);
	if (is_pressing_controls(window))
		return (true);
	return (false);
}

//call every frames
void update_moving_state(my_w_t *window)
{
	window->game.movement.is_moving = is_player_moving(window);
}