/*
** EPITECH PROJECT, 2017
** my_world_2017
** File description:
** menu_loop.c
*/

#include "../../../include/my_world.h"

void draw_menu_sprite(menu_t *objects, ressources_t *rsces)
{
	sfRenderWindow_drawSprite(rsces->window, objects->sprite, NULL);
	objects = objects->next;
	while (objects != NULL) {
		sfRenderWindow_drawRectangleShape(rsces->window,
							objects->rec, NULL);
		objects = objects->next;
	}
}

int check_buttons(menu_t *buttons, ressources_t *rsces, int *size,
							sfClock *my_clock)
{
	if (check_mouse(buttons, rsces, my_clock) == 1)
		*size += 1;
	buttons = buttons->next;
	if (check_mouse(buttons, rsces, my_clock) == 1)
		*size -= 1;
	buttons = buttons->next;
	if (check_mouse(buttons, rsces, my_clock) == 1)
		return (1);
	buttons = buttons->next;
	if (check_mouse(buttons, rsces, my_clock) == 1)
		sfRenderWindow_close(rsces->window);
	return (0);
}

void menu_destroyer(menu_t *menu, sfText *text)
{
	sfText_destroy(text);
}

int menu_loop(menu_t *objects, ressources_t *rsces, sfText *text)
{
	int size = 15;
	char *str = NULL;
	sfClock *my_clock = sfClock_create();

	while (sfRenderWindow_isOpen(rsces->window)) {
		if (menu_events(rsces) == 84)
			return (84);
		if (check_buttons(objects->next, rsces, &size, my_clock) == 1)
			break;
		str = int_to_str(size);
		str = my_str_append(str, " x ");
		str = my_str_append(str, int_to_str(size));
		sfText_setString(text, str);
		sfRenderWindow_clear(rsces->window, sfBlack);
		draw_menu_sprite(objects, rsces);
		sfRenderWindow_drawText(rsces->window, text, NULL);
		sfRenderWindow_display(rsces->window);
	}
	menu_destroyer(objects, text);
	return (size);
}
