/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** move_player_zone.c created: 22/03/18 18:52
*/

#include <my.h>
#include <rpg.h>

bool move_player_zone_up(my_w_t *window, bool check)
{
	if (ZONE_COOR_X - 1 < 0)
		return (false);
	if (check)
		return (true);
	unload_my_zone(window);
	AREA_COOR_X = AREA_TAB_X - 1;
	ZONE_COOR_X--;
	load_my_zone(window);
	return (true);
}

bool move_player_zone_down(my_w_t *window, bool check)
{
	if (ZONE_COOR_X + 1 > ZONE_TAB_X)
		return (false);
	if (check)
		return (true);
	unload_my_zone(window);
	AREA_COOR_X = 0;
	ZONE_COOR_X++;
	load_my_zone(window);
	return (true);
}

bool move_player_zone_left(my_w_t *window, bool check)
{
	if (ZONE_COOR_Y - 1 < 0)
		return (false);
	if (check)
		return (true);
	unload_my_zone(window);
	AREA_COOR_Y = AREA_TAB_Y - 1;
	ZONE_COOR_Y--;
	load_my_zone(window);
	return (true);
}

bool move_player_zone_right(my_w_t *window, bool check)
{
	if (ZONE_COOR_Y - 1 > ZONE_TAB_Y)
		return (false);
	if (check)
		return (true);
	unload_my_zone(window);
	AREA_COOR_Y = 0;
	ZONE_COOR_Y++;
	load_my_zone(window);
	return (true);
}

bool move_player_zone(direction_t dir, my_w_t *window, bool check)
{
	switch (dir) {
		case UP:
			return (move_player_zone_up(window, check));
		case DOWN:
			return (move_player_zone_down(window, check));
		case LEFT:
			return (move_player_zone_left(window, check));
		case RIGHT:
			return (move_player_zone_right(window, check));
	}
}