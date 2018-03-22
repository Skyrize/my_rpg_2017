/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** draw_list
*/

#include "map_editor.h"

void draw_texture_list(texture_list_t *list, sfRenderWindow *window)
{
	while (list) {
		//my_printf("pos = %d  %d\n", (int)list->pos.x, (int)list->pos.y);
		sfRenderWindow_drawSprite(window, list->sprite, NULL);
		list = list->next;
	}
}