/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

void display_hashmap(my_w_t *window, hashmap_t *hashmap, void (*fptr)())
{
	bucket_t *tmp;

	for (unsigned int i = 0; i != hashmap->size; i++) {
		tmp = hashmap->data[i];
		if (tmp != NULL) {
			fptr(window, tmp);
		}
	}
}

int display_scenes(my_w_t *window)
{
	display_list_t *tmp = window->displayed_scenes;

	if (my_strcmp(window->current->key, MAP_SCENE_NAME) == 0)
		if (display_map(window) != 0)
			return (84);
	while (tmp) {
		for (int i = 0; i != OBJS_TYPE_NB; i++) {
			display_hashmap(window, tmp->scene->objs[i],
				&display_bucket_objs);
		}
		display_hashmap(window, tmp->scene->texts,
			&display_bucket_texts);
		tmp = tmp->next;
	}
	return (0);
}
