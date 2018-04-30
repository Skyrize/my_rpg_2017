/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "rpg.h"

void unload_my_tiles(game_t *game)
{
	if (AREA_NAME != NULL)
		clean_displayed_tiles(game);
}

void unload_my_area(game_t *game)
{
	TILE_COOR_X = 0;
	TILE_COOR_Y = 0;
	for (; TILE_COOR_Y != TILE_TAB_Y; TILE_COOR_Y++)
		for (; TILE_COOR_X != TILE_TAB_X; TILE_COOR_X++)
			unload_my_tiles(game);

}

void unload_my_zone(game_t *game)
{
	AREA_COOR_X = 0;
	AREA_COOR_Y = 0;
	for (; AREA_COOR_Y != AREA_TAB_Y; AREA_COOR_Y++)
		for (; AREA_COOR_X != AREA_TAB_X; AREA_COOR_X++)
			unload_my_area(game);
}

int load_my_zone(game_t *game)
{
	const key_word_t zone_keys[] = {
	{"AREA", 3, &getrea, (char *[]) {"ENCOUNTER", "X", "Y", NULL}},
	{"TILE", 3, &get_tile, (char *[]) {"BLOCK", "X", "Y", NULL}},
	{"TEXTURE", 0, &get_tile_texture, NULL}, {NULL, 0, NULL, NULL}};
	get_infos_t infos = {ZONE_FILEPATH, INIT_CHAR, zone_keys, &map_savior};
	sfVector2i zone_pos = {ZONE_COOR_X, ZONE_COOR_Y};
	sfVector2i area_pos = {AREA_COOR_X, AREA_COOR_Y};
	sfVector2i tile_pos = {TILE_COOR_X, TILE_COOR_Y};

	if (check_unexisting_zone(ZONE_NAME) != 0)
		return (84);
	if (analyse_pcf(game, &infos) != 0) {
		MAP.zone_coord = zone_pos;
		my_printf("WARNING: ERROR IN ZONE '%s' INIT !\n", ZONE_NAME);
		return (84);
	}
	MAP.zone_coord = zone_pos;
	MAP.area_coord = area_pos;
	MAP.tile_coord = tile_pos;
	return (0);
}
