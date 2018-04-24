/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** null
*/

#include "my.h"
#include "rpg.h"

texture_t *create_texture(texture_data_t *data)
{
	texture_t *new = malloc(sizeof(texture_t));

	if (!new)
		return (NULL);
	new->priority = data->priority;
	new->texture = data->texture;
	new->animated = data->animated;
	new->rect = data->rect;
	new->rect_start = data->rect_start;
	new->rect_max = data->rect_max;
	new->rect_offset = data->rect_offset;
	return (new);
}