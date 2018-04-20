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
	scene_t *current_scene;

	(void)infos;
	(void)current_list;
	if (check_undefined_scene(window->current, infos[0]) != 0)
		return (84);
	current_scene = window->current->value;
	if (check_already_existing_music(current_scene->music,
		type[1]) != 0)
		return (84);
	current_scene->music = hm_get(AUDIO_LIB, type[1]);
	if (check_unexisting_music(current_scene->music, type[1]) != 0)
		return (84);
	return (0);
}
