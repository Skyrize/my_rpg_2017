/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_scene_not_created(bucket_t *scene, char *file, int line, char *asked)
{
	if (!scene) {
		my_printf("ERROR: IN FILE '%s' AT LINE '%d', ", file, line);
		my_printf("YOU ASKED FOR UNEXISTING SCENE '%S' !\n", asked);
		return (84);
	}
	return (0);
}

int check_invalid_tile_display(tile_list_t *tile, int x, int y, my_w_t *window)
{
	if (!tile) {
		my_printf("WARNING: IN AREA '%s' AT POSITION (%d/%d),",
		AREA_NAME, x, y);
		my_printf(" TILE IS UNINITIALISED !\n");
		return (84);
	}
	return (0);
}

int check_invalid_map_name(my_w_t *window)
{
	if (!ZONE_NAME) {
		my_printf("WARNING: YOU ARE TRYING TO ENTER ZONE AT");
		my_printf("%d/%d BUT IT ISN'T INITIALISED !\n",
		ZONE_COOR_X, ZONE_COOR_Y);
		return (84);
	}
	if (!AREA_NAME) {
		my_printf("WARNING: YOU ARE TRYING TO ENTER AREA AT");
		my_printf("%d/%d BUT IT ISN'T INITIALISED !\n",
		AREA_COOR_X, AREA_COOR_Y);
		return (84);
	}
	return (0);
}

int check_invalid_map_display(my_w_t *window)
{
	if (ZONE_COOR_Y < 0 || ZONE_COOR_Y >= ZONE_TAB_Y
		|| ZONE_COOR_X < 0 || ZONE_COOR_X >= ZONE_TAB_X) {
		my_printf("WARNING: YOU ARE TRYING TO DISPLAY A ZONE WITH INV");
		my_printf("ALID COORD (ZONE-> %d/%d) !\n",
		ZONE_COOR_X, ZONE_COOR_Y);
		return (84);
	}
	if (AREA_COOR_Y < 0 || AREA_COOR_Y >= AREA_TAB_Y
		|| AREA_COOR_X < 0 || AREA_COOR_X >= AREA_TAB_X) {
		my_printf("WARNING: YOU ARE TRYING TO DISPLAY AN AREA WITH ");
		my_printf("INVALID COORD (AREA-> %d/%d) !\n",
		AREA_COOR_X, AREA_COOR_Y);
		return (84);
	}
	return (check_invalid_map_name(window));
}
