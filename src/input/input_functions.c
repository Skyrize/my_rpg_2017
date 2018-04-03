/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** null
*/

#include <SFML/Window/Event.h>
#include "my.h"
#include "rpg.h"

//TODO add controls structure (already create on rpg.h)
void on_key_pressed(my_w_t *window, sfEvent *event)
{
	if (event->key.code == sfKeyZ)
		move_player(UP, window, false);
	if (event->key.code == sfKeyS)
		move_player(DOWN, window, false);
	if (event->key.code == sfKeyQ)
		move_player(LEFT, window, false);
	if (event->key.code == sfKeyD)
		move_player(RIGHT, window, false);
}

void analyse_events(my_w_t *window)
{
	while (sfRenderWindow_pollEvent(window->window, &window->event)) {
		if (window->event.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		if (window->event.type == sfEvtMouseButtonReleased)
			window->click_released = sfTrue;
		if (window->event.type == sfEvtKeyPressed)
			on_key_pressed(window, &window->event);
	}
}
