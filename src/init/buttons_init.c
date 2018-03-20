/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

static const myfunc_t g_tab[] =
{
	{"NEW_GAME", new_game},
	{"OPTION", option},
	{"CREDITS", credits},
	{"CHARACTERISTIC", caracteristique},
	{"INVENTORY", inventory},
	{"MAP", map},
	{"PAUSE", pause},
	{"QUESTS", quetes},
	{"QUIT", quit},
	{"RELOAD", re_load},
	{"RESUME", resume},
	{"SAVE", save},
	{0, 0}
};

int init_button_callback(my_w_t *window, bucket_t *button_bucket)
{
	obj_t *obj = button_bucket->value;
	int i = 0;

	if (!button)
		return (84);
	while (g_tab[i].balise != 0) {
		if (my_fastcmp(g_tab[i].balise, button_bucket->key) == 0)
			obj->callback = g_tab[i].instruction;
		i += 1;
	}
	return (0);
}

int seek_buttons(my_w_t *window, bucket_t *button_bucket)
{
	bucket_t *tmp = button_bucket;

	while (tmp) {
		if (init_button_callback(window, button_bucket) != 0)
			return (84);
		tmp = tmp->next;
	}
	return (0);
}

int read_scenes(my_w_t *window, bucket_t *scene_bucket)
{
	bucket_t *tmp = scene_bucket;
	scene_t *scene;

	while (tmp) {
		scene = tmp->value;
		if (read_hashmap(window, scene->objs[BUTTONS],
			&seek_buttons) != 0)
			return (84);
		tmp = tmp->next;
	}
	return (0);
}

int init_my_buttons(my_w_t *window)
{
	if (read_hashmap(window, window->scenes, &read_scenes) != 0)
		return (84);
	return (0);
}
