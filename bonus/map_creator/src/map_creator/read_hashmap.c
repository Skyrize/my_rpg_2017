/*
** EPITECH PROJECT, 2018
** Sans titre(Espace de travail)
** File description:
** read_hashmap
*/

#include "map_editor.h"

void check_for_big_texture(bucket_t *tmp, texture_list_t *list)
{
	if (!my_strcmp(tmp->key, "LAVA_01")
	|| !my_strcmp(tmp->key, "HOUSE_DOWN_01")
	|| !my_strcmp(tmp->key, "HOUSE_DOWN_02")
	|| !my_strcmp(tmp->key, "HOUSE_DOWN_03")
	|| !my_strcmp(tmp->key, "HOUSE_UP_01")
	|| !my_strcmp(tmp->key, "HOUSE_UP_02")
	|| !my_strcmp(tmp->key, "HOUSE_UP_03")
	|| !my_strcmp(tmp->key, "ROCK_UP_01")
	|| !my_strcmp(tmp->key, "ROCK_DOWN_01")
	|| !my_strcmp(tmp->key, "TREE_DOWN_01")
	|| !my_strcmp(tmp->key, "TREE_UP_01")
	|| !my_strcmp(tmp->key, "WELL_DOWN_01")
	|| !my_strcmp(tmp->key, "WELL_UP_01")
	|| !my_strcmp(tmp->key, "WATER_02")
	|| !my_strcmp(tmp->key, "WATER_SIDE_03_02"))
		add_big_texture_to_list(list, tmp->value);
	else
		add_texture_to_list(list, tmp->value);
}

texture_list_t *read_hashmap_texture(hashmap_t *textures)
{
	texture_list_t *list = malloc(sizeof(*list));
	bucket_t *tmp;

	list->rec = NULL;
	for (unsigned int i = 0; i != textures->size; i++) {
		tmp = textures->data[i];
		while (tmp) {
			check_for_big_texture(tmp, list);
			tmp = tmp->next;
		}
	}
	return (list);
}