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

int display_scene(my_w_t *window)
{
	scene_t *current_scene = hm_get(window->scenes, window->actual_scene);

	if (check_valid_display(current_scene, window->actual_scene) != 0)
		return (84);
	display_hashmap(window, current_scene->objs[BACKGROUNDS],
		&display_bucket_objs);
	display_hashmap(window, current_scene->objs[PNJS],
		&display_bucket_objs);
	display_hashmap(window, current_scene->objs[ITEMS],
		&display_bucket_objs);
	display_hashmap(window, current_scene->objs[BUTTONS],
		&display_bucket_objs);
	display_hashmap(window, current_scene->texts, &display_bucket_texts);
	return (0);
}
