/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

void clean_displayed_scenes(my_w_t *window)
{
	display_list_t *tmp;

	while (window->displayed_scenes) {
		tmp = window->displayed_scenes;
		window->displayed_scenes = tmp->next;
		free(tmp);
	}
}

int clean_displayed_scenes_and_add_back(my_w_t *window, char *scene_name)
{
	display_list_t *tmp;
	int already_in = 0;

	while (window->displayed_scenes) {
		tmp = window->displayed_scenes;
		window->displayed_scenes = tmp->next;
		if (my_strcmp(scene_name, tmp->scene_name) != 0) {
			free(tmp);
			already_in = 1;
		}
	}
	if (already_in == 0) {
		bucket_t *scene = hm_get_bucket(window->scenes, scene_name);
		if (check_unexisting_scene(scene, scene_name) != 0)
			return (84);
		add_scene_to_display_list(scene, window);
	}
	return (0);
}
