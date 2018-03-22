/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** add_texture
*/

#include "map_editor.h"

void assign_texture_to_elem(texture_list_t *list, sfTexture *texture,
								int a, int b)
{
	int x = 810;
	int y = 10;

	list->texture = texture;
	if (!list->texture)
		my_printf("Texture NULLLLLLL\n");
	list->sprite = sfSprite_create();
	if (!list->sprite)
		my_printf("Sprite NULLLLLLL\n");
	sfSprite_setTexture(list->sprite, texture, sfTrue);
	sfSprite_setPosition(list->sprite, V2F(x + a, y + b));
	sfSprite_setScale(list->sprite, V2F(0.5, 0.5));
	list->pos = V2F(x + a, y + b);
	list->next = NULL;
}

void add_texture_to_list(texture_list_t *list, sfTexture *texture)
{
	static int a = 0;
	static int b = 0;
	texture_list_t *new_elem;

	if (!list->sprite) {
		assign_texture_to_elem(list, texture, a, b);
		a += 26;
		return;
	}
	while (list->next)
		list = list->next;
	new_elem = malloc(sizeof(*new_elem));
	assign_texture_to_elem(new_elem, texture, a, b);
	list->next = new_elem;
	a += 26;
}

texture_list_t *read_hashmap_texture(hashmap_t *textures)
{
	texture_list_t *list = malloc(sizeof(*list));
	bucket_t *tmp;

	list->sprite = NULL;
	for (int i = 0; i != textures->size; i++) {
		tmp = textures->data[i];
		while (tmp) {
			add_texture_to_list(list, tmp->value);
			tmp = tmp->next;
		}
	}
	return (list);
}