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

	if (my_strcmp(window->current->key, MAP_SCENE_NAME) == 0)
		if (display_map(window) != 0)
			return (84);
	while (tmp) {
		for (int i = 0; i != OBJS_TYPE_NB; i++) {
			window->error_no = read_hashmap(window,
				tmp->scene->objs[i], &display_objs);
		}
		if (window->error_no != 0)
			return (84);
		if (read_hashmap(window, tmp->scene->texts,
			&display_texts) != 0)
			return (84);
		tmp = tmp->next;
	}
	return (0);
}
