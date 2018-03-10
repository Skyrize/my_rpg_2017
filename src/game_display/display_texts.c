/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

void display_bucket_texts(my_w_t *window, bucket_t *obj)
{
	bucket_t *tmp = obj;
	sfText *display;

	while (tmp) {
		display = tmp->value;
		sfRenderWindow_drawText(window->window, display, NULL);
		tmp = tmp->next;
	}
}
