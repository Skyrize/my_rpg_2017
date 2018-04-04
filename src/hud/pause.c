/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int pause_game(my_w_t *window)
{
	sfRectangleShape *rec = sfRectangleShape_create();

	sfRectangleShape_setSize(rec, (sfVector2f){800, 600});
	sfRectangleShape_setFillColor(rec, (sfColor){0,0,0,128});
	sfRenderWindow_drawRectangleShape(window->window, rec, NULL);
	return (button_display_hide_scene(PAUSE_GAME, NULL, window));
}
