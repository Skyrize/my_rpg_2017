/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

key_word_t init_words[] = {{"SCENE", &get_a_scene},
{"LIST", &get_a_list},
{"INDEX", &get_an_index},
{"OBJ", &get_an_obj},
{"TEXT", &get_a_text},
{"MUSIC", &get_a_music},
{NULL, NULL}};

int get_a_scene(char **infos, char **type, hashmap_t **current_list,
	my_w_t *window)
{
	(void)infos;
	(void)current_list;
	if (init_scene_lists(type[1], window) != 0)
		return (84);
	window->actual_scene = type[1];
	return (0);
}

int get_a_list(char **infos, char **type, hashmap_t **current_list,
	my_w_t *window)
{
	scene_t *current_scene;

	if (my_strcmp(infos[0], "LIST=TEXTS") == 0) {
		current_scene = hm_get(window->scenes, window->actual_scene);
		*current_list = current_scene->texts;
	}
	(void)current_list;
	(void)type;
	return (0);
}

int get_an_index(char **infos, char **type, hashmap_t **current_list,
	my_w_t *window)
{
	scene_t *current_scene = hm_get(window->scenes, window->actual_scene);

	*current_list = current_scene->objs[my_getnbr(type[1])];
	(void)current_list;
	(void)infos;
	return (0);
}

int get_an_obj(char **infos, char **type, hashmap_t **current_list,
	my_w_t *window)
{
	if (init_an_obj(infos, window, *current_list) != 0)
		return (84);
	(void)type;
	return (0);
}

int get_a_text(char **infos, char **type, hashmap_t **current_list,
	my_w_t *window)
{
	if (init_a_text(infos, window, *current_list) != 0)
		return (84);
	(void)type;
	return (0);
}
