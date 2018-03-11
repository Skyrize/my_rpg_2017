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

int display_scene(my_w_t *window, bucket_t *current_scene)
{
	scene_t *scene = current_scene->value;

	if (check_valid_display(scene, window->actual_scene) != 0)
		return (84);
	for (int i = 0; i != OBJS_TYPE_NB; i++) {
		display_hashmap(window, scene->objs[i],
			&display_bucket_objs);
	}
	display_hashmap(window, scene->texts, &display_bucket_texts);
	return (0);
}
