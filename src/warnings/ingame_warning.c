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
		my_printf("YOU ASKED FOR UNEXISTING SCENE '%S' \n!", asked);
		return (84);
	}
	return (0);
}
