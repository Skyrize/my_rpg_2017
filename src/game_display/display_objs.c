/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int display_objs(bucket_t *obj, my_w_t *window)
{
	obj_t *display = obj->value;

	sfRenderWindow_drawRectangleShape(window->window,
		display->obj, NULL);
	time_animation(display, CLOCK_SPEED_MENU, window);
	return (0);
}
