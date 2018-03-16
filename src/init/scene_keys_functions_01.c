/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int get_a_scene(char **infos, char **type, hashmap_t **current_list,
	my_w_t *window)
{
	(void)infos;
	*current_list = window->scenes;
	if (init_scene_lists(infos, window) != 0)
		return (84);
	window->current = hm_get_bucket(*current_list, type[1]);
	return (0);
}

int get_a_list(char **infos, char **type, hashmap_t **current_list,
	my_w_t *window)
{
	scene_t *current_scene;

	if (my_strcmp(infos[0], "LIST=TEXTS") == 0) {
		if (check_undefined_scene(window->current, infos[0]) != 0)
			return (84);
		current_scene = window->current->value;
		*current_list = current_scene->texts;
	}
	(void)current_list;
	(void)type;
	return (0);
}

int get_an_index(char **infos, char **type, hashmap_t **current_list,
	my_w_t *window)
{
	scene_t *current_scene;
	char *asked_list = infos[0];

	if (check_invalid_index(my_getnbr(type[1])) != 0)
		return (84);
	if (check_undefined_scene(window->current, asked_list) != 0)
		return (84);
	current_scene = window->current->value;
	*current_list = current_scene->objs[my_getnbr(type[1])];
	(void)current_list;
	(void)infos;
	return (0);
}

int get_an_obj(char **infos, char **type, hashmap_t **current_list,
	my_w_t *window)
{
	if (check_undefined_scene(window->current, infos[0]) != 0)
		return (84);
	if (check_undefined_list(*current_list, infos[0]) != 0)
		return (84);
	if (check_already_existing_obj(type[1], *current_list) != 0)
		return (84);
	if (init_an_obj(infos, window, *current_list) != 0)
		return (84);
	return (0);
}

int get_a_text(char **infos, char **type, hashmap_t **current_list,
	my_w_t *window)
{
	if (check_undefined_scene(window->current, infos[0]) != 0)
		return (84);
	if (check_undefined_list(*current_list, infos[0]) != 0)
		return (84);
	if (check_already_existing_text(type[0], *current_list) != 0)
		return (84);
	if (init_a_text(infos, window, *current_list) != 0)
		return (84);
	return (0);
}
