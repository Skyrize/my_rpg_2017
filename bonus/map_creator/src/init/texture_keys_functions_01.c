/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int get_a_texture(char **infos, char **type,
	hashmap_t **current_list, my_w_t *window)
{
	texture_t *texture = malloc(sizeof(texture_t));

	if (!texture)
		return (84);
	*current_list = window->textures_lib;
	if (check_already_existing_texture(*current_list, type[1]) != 0)
		return (84);
	texture->texture = NULL;
	texture->animated = sfFalse;
	texture->rect = (sfIntRect){0, 0, 0, 0};
	texture->rect_start = (sfVector2i){0, 0};
	texture->rect_max = (sfVector2i){0, 0};
	texture->rect_offset = (sfVector2i){0, 0};
	hm_add(*current_list, type[1], texture);
	window->current = hm_get_bucket(*current_list, type[1]);
	(void)infos;
	return (0);
}

int get_a_texture_filepath(char **infos, char **type,
	hashmap_t **current_list, my_w_t *window)
{
	texture_t *texture;

	if (check_undefined_texture(window->current, type[0]) != 0)
		return (84);
	texture = window->current->value;
	texture->texture = sfTexture_createFromFile(type[1], NULL);
	if (!texture->texture)
		return (84);
	(void)infos;
	(void)current_list;
	return (0);
}

int get_an_animated(char **infos, char **type,
	hashmap_t **current_list, my_w_t *window)
{
	texture_t *texture;
	sfBool animated;

	if (check_undefined_texture(window->current, type[0]) != 0)
		return (84);
	texture = window->current->value;
	animated = my_getnbr(type[1]);
	if (check_invalid_animated(animated) != 0)
		return (84);
	texture->animated = animated;
	(void)infos;
	(void)current_list;
	return (0);
}

int get_a_rect_values(char **infos, char **type,
	hashmap_t **current_list, my_w_t *window)
{
	texture_t *texture;
	char **left = my_str_to_word_array(infos[1], KEYWORD_SEPARATOR_CHAR);
	char **top = my_str_to_word_array(infos[2], KEYWORD_SEPARATOR_CHAR);
	char **width = my_str_to_word_array(infos[3], KEYWORD_SEPARATOR_CHAR);
	char **height = my_str_to_word_array(infos[4], KEYWORD_SEPARATOR_CHAR);

	if (check_undefined_texture(window->current, infos[0]) != 0)
		return (84);
	texture = window->current->value;
	if (!left || !top || !width || !height)
		return (84);
	texture->rect = (sfIntRect){my_getnbr(left[1]), my_getnbr(top[1]),
		my_getnbr(width[1]), my_getnbr(height[1])};
	free_char_2d(left);
	free_char_2d(top);
	free_char_2d(width);
	free_char_2d(height);
	(void)type;
	(void)current_list;
	return (0);
}

int get_a_rect_max_values(char **infos, char **type,
	hashmap_t **current_list, my_w_t *window)
{
	texture_t *texture;
	char **x = my_str_to_word_array(infos[1], KEYWORD_SEPARATOR_CHAR);
	char **y = my_str_to_word_array(infos[2], KEYWORD_SEPARATOR_CHAR);

	if (check_undefined_texture(window->current, infos[0]) != 0)
		return (84);
	texture = window->current->value;
	texture->rect_max = (sfVector2i){my_getnbr(x[1]), my_getnbr(y[1])};
	free_char_2d(x);
	free_char_2d(y);
	(void)type;
	(void)current_list;
	return (0);
}
