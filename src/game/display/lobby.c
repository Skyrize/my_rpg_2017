/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int display_scenes(window_t *window, game_t *game)
{
	display_list_t *tmp = DISPLAYED_SCENES;

	if (my_strcmp(tmp->scene_name, MAP_SCENE_NAME) == 0)
		if (display_map(window, game) != 0)
			return (84);
	while (tmp) {
		if (display_objs(tmp->scene->objs, window) != 0)
			return (84);
		if (read_hashmap(window, NULL, tmp->scene->texts,
			&display_texts) != 0)
			return (84);
		tmp = tmp->next;
	}
	return (0);
}
