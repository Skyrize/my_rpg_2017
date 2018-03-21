/*
** EPITECH PROJECT, 2017
** my_world_2017
** File description:
** events.c created: 01/02/18 13:25
*/

#include "map_editor.h"

void left_click_event(ressources_t *rsces)
{
	return;
}

void right_click_event(ressources_t *rsces)
{
	return;
}

void on_event(ressources_t *rsces, sfEvent event)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(rsces->window);
	if (event.type == sfEvtMouseButtonPressed) {
		if (event.mouseButton.button == sfMouseLeft)
			left_click_event(rsces);
		else if (event.mouseButton.button == sfMouseRight)
			right_click_event(rsces);
	}
}
