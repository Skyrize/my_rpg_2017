/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** move_player_zone.c created: 22/03/18 18:52
*/

#include <my.h>
#include <rpg.h>

bool move_player_zone_up(game_t *game, bool check)
{
	if (ZONE_COOR_X - 1 < 0)
		return (false);
	if (check)
		return (true);
	unload_my_zone(game);
	AREA_COOR_X = AREA_TAB_X - 1;
	ZONE_COOR_X--;
	load_my_zone(game);
	return (true);
}

bool move_player_zone_down(game_t *game, bool check)
{
	if (ZONE_COOR_X + 1 > ZONE_TAB_X)
		return (false);
	if (check)
		return (true);
	unload_my_zone(game);
	AREA_COOR_X = 0;
	ZONE_COOR_X++;
	load_my_zone(game);
	return (true);
}

bool move_player_zone_left(game_t *game, bool check)
{
	if (ZONE_COOR_Y - 1 < 0)
		return (false);
	if (check)
		return (true);
	unload_my_zone(game);
	AREA_COOR_Y = AREA_TAB_Y - 1;
	ZONE_COOR_Y--;
	load_my_zone(game);
	return (true);
}

bool move_player_zone_right(game_t *game, bool check)
{
	if (ZONE_COOR_Y - 1 > ZONE_TAB_Y)
		return (false);
	if (check)
		return (true);
	unload_my_zone(game);
	AREA_COOR_Y = 0;
	ZONE_COOR_Y++;
	load_my_zone(game);
	return (true);
}

bool move_player_zone(direction_t dir, game_t *game, bool check)
{
	switch (dir) {
		case UP:
			return (move_player_zone_up(game, check));
		case DOWN:
			return (move_player_zone_down(game, check));
		case LEFT:
			return (move_player_zone_left(game, check));
		case RIGHT:
			return (move_player_zone_right(game, check));
	}
	return (false);
}