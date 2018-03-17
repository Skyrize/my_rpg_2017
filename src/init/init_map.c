/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int load_my_zone(my_w_t *window)
{
	const key_word_t zone_keys[] = {
	{"AREA", 3, &get_an_area, (char *[]) {"ENCOUNTER", "X", "Y", NULL}},
	{"TILE", 3, &get_a_tile, (char *[]) {"BLOCK", "X", "Y", NULL}},
	{"TEXTURE", 1, &get_a_tile_texture, (char *[]) {"PRIORITY", NULL}},
	{NULL, 0, NULL, NULL}};
	get_infos_t infos;

	if (check_unexisting_zone(ZONE_NAME) != 0)
		return (84);
	infos.filepath = ZONE_FILEPATH;
	infos.indicator = INIT_INDICATOR;
	infos.keys = zone_keys;
	infos.savior = &map_savior;
	if (analyse_my_project_config_file(window, &infos) != 0) {
		my_printf("WARNING: ERROR IN ZONE INIT !\n");
		return (84);
	}
	return (0);
}

int init_my_map(my_w_t *window)
{
	const key_word_t map_keys[] = {
	{"ZONE", 3, &get_a_map, (char *[]) {"FILEPATH", "X", "Y", NULL}},
	{NULL, 0, NULL, NULL}};
	get_infos_t infos = {"pcf/map.pcf", INIT_INDICATOR, map_keys,
	&map_savior};

	for (int y = 0; y != ZONE_TAB_Y; y++)
		for (int x = 0; x != ZONE_TAB_X; x++) {
			window->map.zones[y][x].name = NULL;
			window->map.zones[y][x].filepath = NULL;
		}
	for (int y = 0; y != AREA_TAB_Y; y++)
		for (int x = 0; x != AREA_TAB_X; x++)
			window->map.areas[y][x].name = NULL;
	if (analyse_my_project_config_file(window, &infos) != 0) {
		my_printf("WARNING: ERROR IN MAP INIT !\n");
		return (84);
	}
	return (0);
}
