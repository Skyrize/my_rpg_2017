/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** move_player_b.c created: 22/03/18 18:50
*/

#include <my.h>
#include <rpg.h>

bool move_player_aera_up(my_w_t *window, bool check)
{
	if (AREA_COOR_Y - 1 < 0)
		return (move_player_zone(UP, window, check));
	if (!(window->map.areas[AREA_COOR_Y - 1][AREA_COOR_X].name))
		return (false);
	if (check)
		return (true);
	TILE_COOR_Y = TILE_TAB_Y - 1;
	AREA_COOR_Y--;
	return (true);
}

bool move_player_aera_down(my_w_t *window, bool check)
{
	if (AREA_COOR_Y + 1 > AREA_TAB_Y)
		return (move_player_zone(DOWN, window, check));
	if (!(window->map.areas[AREA_COOR_Y + 1][AREA_COOR_X].name))
		return (false);
	if (check)
		return (true);
	TILE_COOR_Y = 0;
	AREA_COOR_Y++;
	return (true);
}

bool move_player_aera_left(my_w_t *window, bool check)
{
	if (AREA_COOR_X - 1 < 0)
		return (move_player_zone(LEFT, window, check));
	if (!(window->map.areas[AREA_COOR_Y][AREA_COOR_X - 1].name))
		return (false);
	if (check)
		return (true);
	TILE_COOR_X = TILE_TAB_X - 1;
	AREA_COOR_X--;
	return (true);
}

bool move_player_aera_right(my_w_t *window, bool check)
{
	if (AREA_COOR_X + 1 > AREA_TAB_X)
		return (move_player_zone(RIGHT, window, check));
	if (!(window->map.areas[AREA_COOR_Y][AREA_COOR_X + 1].name))
		return (false);
	if (check)
		return (true);
	TILE_COOR_X = 0;
	AREA_COOR_X++;
	return (true);
}

bool move_player_area(direction_t dir, my_w_t *window, bool check)
{
	switch (dir) {
		case UP:
			return (move_player_aera_up(window, check));
		case DOWN:
			return (move_player_aera_down(window, check));
		case LEFT:
			return (move_player_aera_left(window, check));
		case RIGHT:
			return (move_player_aera_right(window, check));
	}
	return (false);
}