/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_unexisting_scene(bucket_t *scene, char *scene_name)
{
	if (!scene) {
		my_printf("WARNING: YOU ASKED FOR UNEXISTING '%s' SCENE !\n",
		scene_name);
		return (84);
	}
	return (0);
}

int check_valid_display(scene_t *current_scene, char *scene_seeked)
{
	if (!current_scene) {
		my_printf("WARNING: INVALID DISPLAY, CAN'T FIND %s\n",
		scene_seeked);
		return (84);
	}
	return (0);
}
