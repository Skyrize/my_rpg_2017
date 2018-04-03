/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** move_player.c created: 22/03/18 18:31
*/

#include <my.h>
#include <rpg.h>

bool move_player_up(my_w_t *window, bool check)
{
	if (TILE_COOR_Y - 1 <= -1)
		return (move_player_area(UP, window, check));
	if (check)
		return (true);
	TILE_COOR_Y--;
	return (true);
}

bool move_player_down(my_w_t *window, bool check)
{
	if (TILE_COOR_Y + 1 > TILE_TAB_Y - 2)
		return (move_player_area(DOWN, window, check));
	if (check)
		return (true);
	TILE_COOR_Y++;
	return (true);
}

bool move_player_left(my_w_t *window, bool check)
{
	if (TILE_COOR_X - 1 <= -1)
		return (move_player_area(LEFT, window, check));
	if (check)
		return (true);
	TILE_COOR_X--;
	return (true);
}

bool move_player_right(my_w_t *window, bool check)
{
	if (TILE_COOR_X + 1 > TILE_TAB_X - 1)
		return (move_player_area(RIGHT, window, check));
	if (check)
		return (true);
	TILE_COOR_X++;
	return (true);
}

bool move_player(direction_t dir, my_w_t *window, bool check)
{
	if (my_strcmp(window->current->key, "GAME") != 0)
		return (false);
	switch (dir) {
		case UP:
			return (move_player_up(window, check));
		case DOWN:
			return (move_player_down(window, check));
		case LEFT:
			return (move_player_left(window, check));
		case RIGHT:
			return (move_player_right(window, check));
	}
	return (false);
}