/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_undefined_scene(scene_t *current_scene, char *asked_list)
{
	if (!current_scene) {
		my_printf("WARNING: YOU ASKED FOR '%s' BUT SCENE ISN'T ",
		asked_list);
		my_printf("DEFINED !\n");
		return (84);
	}
	return (0);
}
