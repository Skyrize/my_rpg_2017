/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int get_a_texture(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	texture_t *texture = create_texture(&(texture_data_t){0, NULL, 0,
	INTRECT(0, 0, 0, 0), V2I(0, 0), V2I(0, 0), V2I(0, 0)});

	if (!texture)
		return (84);
	*current_list = TEXTURES_LIB;
	if (check_already_existing_texture(*current_list, type[1]) != 0)
		return (84);
	hm_add(*current_list, type[1], texture);
	CURRENT_SCENE = hm_get_bucket(*current_list, type[1]);
	(void)infos;
	return (0);
}

int get_a_texture_filepath(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	texture_t *texture;

	if (check_undefined_texture(CURRENT_SCENE, type[0]) != 0)
		return (84);
	texture = CURRENT_SCENE->value;
	if (!texture)
		return (84);
	texture->texture = sfTexture_createFromFile(type[1], NULL);
	if (!texture->texture)
		return (84);
	(void)infos;
	(void)current_list;
	return (0);
}

int is_texture_animated(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	texture_t *texture;
	sfBool animated;

	if (check_undefined_texture(CURRENT_SCENE, type[0]) != 0)
		return (84);
	texture = CURRENT_SCENE->value;
	if (!texture)
		return (84);
	animated = my_getnbr(type[1]);
	if (check_invalid_animated(animated) != 0)
		return (84);
	texture->animated = animated;
	(void)infos;
	(void)current_list;
	return (0);
}

int get_a_priority(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	texture_t *texture;
	int priority;

	if (check_undefined_texture(CURRENT_SCENE, type[0]) != 0)
		return (84);
	texture = CURRENT_SCENE->value;
	if (!texture)
		return (84);
	priority = my_getnbr(type[1]);
	if (check_invalid_priority(priority, CURRENT_SCENE->key) != 0)
		return (84);
	texture->priority = priority;
	(void)infos;
	(void)current_list;
	return (0);
}
