/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** tiles.c
*/

#include "rpg.h"
#include "my.h"

static const remarkable_tile_t tile_tab[] = {
	{"PENNY", update_random_pnj_dialogue, {V2I(3, 4), V2I(0, 0), V2I(6, 3)}},
	{NULL, NULL, {V2I(-1, -1), V2I(-1, -1), V2I(-1, -1)}},
};

int compare_coords(const remarkable_tile_t *get_tile, game_t *game)
{
	sfVector2i tile = get_tile->coord.tile;

	if ((TILE_COOR_X == tile.x && TILE_COOR_Y == tile.y)
	|| (TILE_COOR_X == tile.x + 1 && TILE_COOR_Y == tile.y)
	|| (TILE_COOR_X == tile.x - 1 && TILE_COOR_Y == tile.y)
	|| (TILE_COOR_X == tile.x && TILE_COOR_Y == tile.y + 1)
	|| (TILE_COOR_X == tile.x && TILE_COOR_Y == tile.y - 1)) {
		if (get_tile->fptr(get_tile->name, game) != 0)
			return (84);
		return (1);
	}
	return (0);
}

int check_special_tiles_around(game_t *game)
{
	int my_errno = 0;

	for (int i = 0; tile_tab[i].fptr; i++) {
		if (ZONE_COOR_X == tile_tab[i].coord.zone.x
		&& ZONE_COOR_Y == tile_tab[i].coord.zone.y
		&& AREA_COOR_X == tile_tab[i].coord.area.x
		&& AREA_COOR_Y == tile_tab[i].coord.area.y)
			my_errno = compare_coords(&tile_tab[i], game);
		if (my_errno == 1)
			return (0);
		else if (my_errno == 84)
			return (84);
	}
	if (update_nothing_here(game) != 0)
		return (84);
	return (0);
}