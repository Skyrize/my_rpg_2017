/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** move_player.c created: 22/03/18 17:55
*/

#include <my.h>
#include <rpg.h>

bool set_ply_zone(sfVector2i pos_zone, window_t *window, bool check)
{
	if (pos_zone.x == ZONE_COOR_X && pos_zone.y == ZONE_COOR_Y)
		return (true);
	if (pos_zone.x > ZONE_TAB_X || pos_zone.x < 0)
		return (false);
	if (pos_zone.y > ZONE_TAB_Y || pos_zone.y < 0)
		return (false);
	if (check)
		return (true);
	unload_my_zone(window);
	ZONE_COOR_Y = pos_zone.x;
	ZONE_COOR_X = pos_zone.y;
	load_my_zone(window);
	return (true);
}

bool set_ply_area(sfVector2i pos_area, window_t *window, bool check)
{
	if (pos_area.x == AREA_COOR_X && pos_area.y == AREA_COOR_Y)
		return (true);
	if (pos_area.x > AREA_TAB_X || pos_area.x < 0)
		return (false);
	if (pos_area.y > AREA_TAB_Y || pos_area.y < 0)
		return (false);
	if (check)
		return (true);
	AREA_COOR_X = pos_area.x;
	AREA_COOR_Y = pos_area.y;
	return (true);
}

bool set_ply_tile(sfVector2i pos_tile, window_t *window, bool check)
{
	if (pos_tile.x == TILE_COOR_X && pos_tile.y == TILE_COOR_Y)
		return (true);
	if (pos_tile.x > TILE_TAB_X || pos_tile.x < 0)
		return (false);
	if (pos_tile.y > TILE_TAB_Y || pos_tile.y < 0)
		return (false);
	if (check)
		return (true);
	TILE_COOR_X = pos_tile.x;
	TILE_COOR_Y = pos_tile.y;
	return (true);
}

bool set_player_position(sfVector2i pos_tile, sfVector2i pos_aera,
			 sfVector2i pos_zone, window_t *window)
{
	if (!(set_ply_zone(pos_zone, window, true) &&
		set_ply_area(pos_aera, window, true) &&
		set_ply_tile(pos_tile, window, true)))
		return (false);
	set_ply_zone(pos_zone, window, false);
	set_ply_area(pos_aera, window, false);
	set_ply_tile(pos_tile, window, false);
	return (true);
}