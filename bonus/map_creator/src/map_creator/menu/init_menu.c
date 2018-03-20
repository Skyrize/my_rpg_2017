/*
** EPITECH PROJECT, 2017
** my_world_2017
** File description:
** init_menu.c
*/

#include "../../../include/my_world.h"

menu_t *create_button(const char *path, sfVector2f pos)
{
	menu_t *object = malloc(sizeof(*object));
	v2f size;
	sfVector2u size_u;

	object->texture = sfTexture_createFromFile(path, NULL);
	object->pos = pos;
	object->state = 0;
	object->rec = sfRectangleShape_create();
	sfRectangleShape_setTexture(object->rec, object->texture, sfTrue);
	size_u = sfTexture_getSize(object->texture);
	size.x = size_u.x * 1.5;
	size.y = size_u.y * 1.5;
	sfRectangleShape_setSize(object->rec, size);
	size = sfRectangleShape_getSize(object->rec);
	size.x /= 2;
	size.y /= 2;
	sfRectangleShape_setOrigin(object->rec, size);
	sfRectangleShape_setPosition(object->rec, pos);
	object->next = NULL;
	return (object);
}

menu_t *create_sprite(const char *path, sfVector2f pos)
{
	menu_t *object = malloc(sizeof(*object));

	object->texture = sfTexture_createFromFile(path, NULL);
	object->pos = pos;
	object->state = 0;
	object->sprite = sfSprite_create();
	sfSprite_setTexture(object->sprite, object->texture, sfTrue);
	sfSprite_setPosition(object->sprite, pos);
	object->next = NULL;
	return (object);
}

void add_to_list(menu_t *list, menu_t *object)
{
	while (list->next)
		list = list->next;
	list->next = object;
}

int start_menu(ressources_t *rsces)
{
	menu_t *menu = create_sprite("img/menu.png", V2F(0, 0));
	sfFont *font = sfFont_createFromFile("font/my_font.otf");
	sfText *text = sfText_create();

	sfText_setFont(text, font);
	sfText_setCharacterSize(text, 65);
	sfText_setPosition(text, V2F(820, 520));
	add_to_list(menu, create_button("img/button_up.png", V2F(920, 495)));
	add_to_list(menu, create_button("img/button_down.png", V2F(920, 635)));
	add_to_list(menu, create_button("img/button_play.png", V2F(600, 800)));
	add_to_list(menu, create_button("img/button_quit.png", V2F(1000, 800)));
	return (menu_loop(menu, rsces, text));
}
