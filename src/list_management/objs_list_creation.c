/*
** EPITECH PROJECT, 2017
** my_rpg_2017
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

obj_t *create_obj(obj_data_t *data, texture_t *texture)
{
	obj_t *new_obj = malloc(sizeof(obj_t));
	sfVector2f rec_size;

	if (check_unexisting_texture(texture->texture, data->type) != 0
	|| new_obj == NULL)
		return (NULL);
	rec_size.x = texture->rect.width;
	rec_size.y = texture->rect.height;
	new_obj->obj = sfRectangleShape_create();
	if (!new_obj->obj)
		return (NULL);
	sfRectangleShape_setTexture(new_obj->obj, texture->texture, sfTrue);
	sfRectangleShape_setSize(new_obj->obj, rec_size);
	new_obj->callback = NULL;
	return (new_obj);
}

int add_obj_to_list(obj_data_t *data, hashmap_t *list, my_w_t *window)
{
	texture_t *texture = hm_get(window->textures_lib, data->type);
	obj_t *new_obj = create_obj(data, texture);

	if (new_obj == NULL)
		return (84);
	new_obj->obj_rect.animated = texture->animated;
	new_obj->obj_rect.rect = texture->rect;
	new_obj->obj_rect.rect_start = texture->rect_start;
	new_obj->obj_rect.rect_max = texture->rect_max;
	new_obj->obj_rect.rect_offset = texture->rect_offset;
	sfRectangleShape_setTextureRect(new_obj->obj, texture->rect);
	sfRectangleShape_setPosition(new_obj->obj, data->position);
	hm_add(list, data->name, new_obj);
	return (0);
}

display_list_t *create_a_display(char *name, scene_t *scene)
{
	display_list_t *display = malloc(sizeof(display_list_t));

	if (!display)
		return (NULL);
	display->scene = scene;
	display->scene_name = name;
	display->next = NULL;
	return (display);
}

int add_scene_to_list(bucket_t *scene, my_w_t *window)
{
	display_list_t *display = create_a_display(scene->key, scene->value);
	display_list_t *tmp = window->displayed_scenes;

	if (!display)
		return (84);
	if (!tmp) {
		window->displayed_scenes = display;
		return (0);
	}
	if (tmp->scene->priority >= display->scene->priority) {
		display->next = tmp;
		window->displayed_scenes = display;
		return (0);
	}
	while (tmp->next
		&& display->scene->priority > tmp->next->scene->priority)
		tmp = tmp->next;
	display->next = tmp->next;
	tmp->next = display;
	return (0);
}
