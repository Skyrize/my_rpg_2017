/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int get_a_music(char **infos, char **type, hashmap_t **current_list,
	my_w_t *window)
{
	scene_t *current_scene = hm_get(window->scenes, window->actual_scene);

	(void)infos;
	(void)current_list;
	current_scene->music = hm_get(window->audio_lib, type[1]);
	if (check_invalid_music(current_scene->music, type[1]) != 0)
		return (84);
	return (0);
}
