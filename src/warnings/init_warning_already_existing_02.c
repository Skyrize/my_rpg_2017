/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_already_existing_scene(bucket_t *scene, char *scene_name)
{
	if (scene != NULL) {
		my_printf("WARNING: SCENE '%s' IS REDECLARED !\n", scene_name);
		return (84);
	}
	return (0);
}

int check_already_existing_music(sfMusic *music, char *music_name)
{
	if (music != NULL) {
		my_printf("WARNING: SCENE CAN CONTAIN ONLY ONE MUSIC");
		my_printf(", PLEASE REMOVE '%s' !\n", music_name);
		return (84);
	}
	return (0);
}
