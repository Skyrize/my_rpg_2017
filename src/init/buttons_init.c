/*
** EPITECH PROJECT, 2017
** my_prg_2017
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
	{"EXIT", exit_game},
	{"HOME", menu_principale},
	{"SONG", manage_song},
	{"FRAME_RATE_MORE", frame_rate_more},
	{"FRAME_RATE_LESS", frame_rate_less},
	{0, 0}
};

int init_button_callback(bucket_t *button_bucket)
{
	obj_t *button = button_bucket->value;
	int i = 0;

	if (!button)
		return (84);
	if (button->button == sfFalse)
		return (0);
	for (; g_tab[i].balise != 0; i++) {
		if (my_fastcmp(g_tab[i].balise, button_bucket->key) == 0) {
			button->callback = g_tab[i].instruction;
			break;
		}
	}
	if (g_tab[i].balise == 0) {
		my_printf("WARNING: CAN'T FIND BUTTON '%s' !\n",
		button_bucket->key);
		return (84);
	}
	return (0);
}

int seek_buttons(my_w_t *window, bucket_t *button_bucket)
{
	bucket_t *tmp = button_bucket;

	while (tmp) {
		if (init_button_callback(button_bucket) != 0)
			return (84);
		tmp = tmp->next;
	}
	(void)window;
	return (0);
}

int read_scenes(my_w_t *window, bucket_t *scene_bucket)
{
	bucket_t *tmp = scene_bucket;
	scene_t *scene;
	int error_no = 0;

	while (tmp) {
		scene = tmp->value;
		for (int i = 0; i != OBJS_TYPE_NB; i++) {
			error_no += read_hashmap(window, scene->objs[i],
				&seek_buttons);
		}
		if (error_no != 0)
			return (84);
		tmp = tmp->next;
	}
	return (0);
}

int init_my_buttons(my_w_t *window)
{
	POS_MOUSE = (sfVector2i){0, 0};
	if (read_hashmap(window, window->scenes, &read_scenes) != 0)
		return (84);
	return (0);
}
