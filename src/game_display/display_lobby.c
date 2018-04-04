/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int display_scenes(my_w_t *window)
{
	display_list_t *tmp = window->displayed_scenes;

	if (my_strcmp(tmp->scene_name, MAP_SCENE_NAME) == 0)
		if (display_map(window) != 0)
			return (84);
	while (tmp) {
		if (display_objs(tmp->scene->objs, window) != 0)
			return (84);
		if (read_hashmap(window, tmp->scene->texts,
			&display_texts) != 0)
			return (84);
		tmp = tmp->next;
	}
	return (0);
}
