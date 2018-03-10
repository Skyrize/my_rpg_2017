/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** null
*/

#include "my.h"
#include "rpg.h"

int add_text_to_list(text_infos_t *text, my_w_t *window,
	hashmap_t *current_list)
{
	sfText *sftext;
	sfFont *font = hm_get(window->fonts_lib, text->text_font[1]);

	if (check_unexisting_font(font, text->text_font[1]) != 0)
		return (84);
	sftext = sfText_create();
	if (!sftext)
		return (84);
	replace_char(text->text[1], '_', ' ');
	sfText_setString(sftext, text->text[1]);
	sfText_setFont(sftext, font);
	sfText_setCharacterSize(sftext, my_getnbr(text->text_charac_size[1]));
	sfText_setPosition(sftext, (sfVector2f){my_getnbr(text->text_x[1]),
		my_getnbr(text->text_y[1])});
	hm_add(current_list, text->text[1], sftext);
	return (0);
}

game_objs_t *init_game_objs(char *obj_key, sfVector2f *position, my_w_t *window)
{
	game_objs_t *new_obj = malloc(sizeof(game_objs_t));
	sfTexture *texture = hm_get(window->textures_lib, obj_key);
	sfVector2u texture_size;
	sfVector2f rec_size;

	if (check_invalid_texture(texture, obj_key) != 0 || new_obj == NULL)
		return (NULL);
	texture_size = sfTexture_getSize(texture);
	rec_size.x = texture_size.x;
	rec_size.y = texture_size.y;
	new_obj->obj = sfRectangleShape_create();
	if (!new_obj->obj)
		return (NULL);
	sfRectangleShape_setTexture(new_obj->obj, texture, sfTrue);
	sfRectangleShape_setSize(new_obj->obj, rec_size);
	sfRectangleShape_setPosition(new_obj->obj, *position);
	new_obj->callback = NULL;
	return (new_obj);
}

int add_obj_to_list(char *obj_key, hashmap_t *list,
	sfVector2f *position, my_w_t *window)
{
	game_objs_t *new_obj = init_game_objs(obj_key, position, window);

	if (new_obj == NULL)
		return (84);
	hm_add(list, obj_key, new_obj);
	return (0);
}
