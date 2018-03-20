/*
** EPITECH PROJECT, 2017
** my_world_2017
** File description:
** events.c created: 01/02/18 13:25
*/

#include "../../include/my_world.h"
#include <SFML/Window/Event.h>

void on_keyboard_zoom(ressources_t *rsces, sfEvent event)
{
	if (sfKeyboard_isKeyPressed(sfKeyLControl)) {
		if (sfKeyboard_isKeyPressed(sfKeyEqual)) {
			rsces->cam->scale.x *= 1.2;
			rsces->cam->scale.y *= 1.2;
		} else if (sfKeyboard_isKeyPressed(sfKeyDash)) {
			rsces->cam->scale.x /= 1.2;
			rsces->cam->scale.y /= 1.2;
		}
	}
}

void on_keyboard_gui(ressources_t *rsces, sfEvent event)
{
	if (sfKeyboard_isKeyPressed(sfKeyG) && rsces->gui->grid == 0)
		rsces->gui->grid = 1;
	else if (sfKeyboard_isKeyPressed(sfKeyG))
		rsces->gui->grid = 0;
	else if (sfKeyboard_isKeyPressed(sfKeyM)) {
		rsces->gui->mode += 1;
		if (rsces->gui->mode == 3)
			rsces->gui->mode = 1;
	}
}

void on_keyboard_edit_map(ressources_t *rsces, sfEvent event)
{
	if (rsces->gui->mode == 1)
		edit_map_point(rsces);
	else if (rsces->gui->mode == 2)
		edit_map_tile(rsces);
}

void on_keyboard(ressources_t *rsces, sfEvent event)
{
	if (sfKeyboard_isKeyPressed(sfKeyLeft))
		if (rsces->cam->x >= 0.1)
			rsces->cam->x -= 0.1;
	if (sfKeyboard_isKeyPressed(sfKeyRight))
		if (rsces->cam->x <= 6.2)
			rsces->cam->x += 0.1;
	if (sfKeyboard_isKeyPressed(sfKeyUp))
		if (rsces->cam->y <= 3)
			rsces->cam->y += 0.1;
	if (sfKeyboard_isKeyPressed(sfKeyDown))
		if (rsces->cam->y >= 2.1)
			rsces->cam->y -= 0.1;
	on_keyboard_zoom(rsces, event);
	on_keyboard_gui(rsces, event);
	on_keyboard_edit_map(rsces, event);
}

void on_event(ressources_t *rsces, sfEvent event)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(rsces->window);
	if (event.type == sfEvtKeyPressed) {
		if (event.key.code == sfKeyLeft || event.key.code == sfKeyRight
		|| event.key.code == sfKeyUp || event.key.code == sfKeyDown)
			sfMusic_play(rsces->sounds->pop);
		on_keyboard(rsces, event);
	}
	if (event.type == sfEvtMouseButtonPressed)
		if (event.mouseButton.button == sfMouseLeft)
			rsces->gui->click = true;
	if (event.type == sfEvtMouseButtonReleased)
		if (event.mouseButton.button == sfMouseLeft)
			rsces->gui->click = false;
}
