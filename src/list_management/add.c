/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int add_text_to_list(text_data_t *data, hashmap_t *current_list)
{
	sfText *sftext;

	if (check_already_existing_text(data->name, current_list) != 0)
		return (84);
	sftext = sfText_create();
	if (!sftext)
		return (84);
	sfText_setString(sftext, data->text);
	sfText_setFont(sftext, data->font);
	sfText_setCharacterSize(sftext, data->charac_size);
	sfText_setPosition(sftext, data->position);
	hm_add(current_list, data->name, sftext);
	return (0);
}

int add_obj_to_list(obj_data_t *data, hashmap_t *list, window_t *window)
{
	obj_t *new_obj;

	if (check_already_existing_obj(data->name, list) != 0)
		return (84);
	new_obj = create_obj(data, window);
	if (new_obj == NULL)
		return (84);
	hm_add(list, data->name, new_obj);
	return (0);
}

int add_scene_to_display_list(bucket_t *scene, window_t *window)
{
	display_list_t *display = create_a_display(scene->key, scene->value);
	display_list_t *tmp = DISPLAYED_SCENES;

	if (!display)
		return (84);
	if (!tmp) {
		DISPLAYED_SCENES = display;
		return (0);
	}
	if (tmp->scene->priority >= display->scene->priority) {
		display->next = tmp;
		DISPLAYED_SCENES = display;
		return (0);
	}
	while (tmp->next
		&& display->scene->priority > tmp->next->scene->priority)
		tmp = tmp->next;
	display->next = tmp->next;
	tmp->next = display;
	return (0);
}

int add_tile_to_list(char *texture, window_t *window)
{
	tile_list_t *display = create_a_tile(texture, window);
	tile_list_t *tmp = TILE_LIST;

	if (!display)
		return (84);
	if (!tmp) {
		TILE_LIST = display;
		return (0);
	}
	if (tmp->tile->priority >= display->tile->priority) {
		display->next = tmp;
		TILE_LIST = display;
		return (0);
	}
	while (tmp->next
		&& display->tile->priority > tmp->next->tile->priority)
		tmp = tmp->next;
	display->next = tmp->next;
	tmp->next = display;
	return (0);
}
