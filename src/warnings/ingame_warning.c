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
