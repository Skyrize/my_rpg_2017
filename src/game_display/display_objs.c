/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

void display_bucket_objs(my_w_t *window, bucket_t *obj)
{
	bucket_t *tmp = obj;
	game_objs_t *display;

	while (tmp) {
		display = tmp->value;
		sfRenderWindow_drawRectangleShape(window->window,
			display->obj, NULL);
		tmp = tmp->next;
	}
}
