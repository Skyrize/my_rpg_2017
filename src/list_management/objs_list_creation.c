/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** null
*/

#include "my.h"
#include "rpg.h"

int add_text_to_list(text_data_t *data, hashmap_t *current_list)
{
	sfText *sftext = sfText_create();

	if (!sftext)
		return (84);
	sfText_setString(sftext, data->text);
	sfText_setFont(sftext, data->font);
	sfText_setCharacterSize(sftext, data->charac_size);
	sfText_setPosition(sftext, data->position);
	hm_add(current_list, data->name, sftext);
	return (0);
}

game_objs_t *init_game_objs(obj_data_t *data, my_w_t *window)
{
	game_objs_t *new_obj = malloc(sizeof(game_objs_t));
	sfTexture *texture = hm_get(window->textures_lib, data->type);
	sfVector2u texture_size;
	sfVector2f rec_size;

	if (check_invalid_texture(texture, data->type) != 0 || new_obj == NULL)
		return (NULL);
	texture_size = sfTexture_getSize(texture);
	rec_size.x = texture_size.x;
	rec_size.y = texture_size.y;
	new_obj->obj = sfRectangleShape_create();
	if (!new_obj->obj)
		return (NULL);
	sfRectangleShape_setTexture(new_obj->obj, texture, sfTrue);
	sfRectangleShape_setSize(new_obj->obj, rec_size);
	sfRectangleShape_setPosition(new_obj->obj, data->position);
	new_obj->callback = NULL;
	return (new_obj);
}

int add_obj_to_list(obj_data_t *data, hashmap_t *list, my_w_t *window)
{
	game_objs_t *new_obj = init_game_objs(data, window);

	if (new_obj == NULL)
		return (84);
	hm_add(list, data->name, new_obj);
	return (0);
}
