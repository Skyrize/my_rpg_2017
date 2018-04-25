/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** null
*/

#include <SFML/Window/Event.h>
#include "my.h"
#include "rpg.h"

void analyse_events(window_t *window, game_t *game)
{
	while (sfRenderWindow_pollEvent(window->window, &window->event)) {
		if (window->event.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		if (window->event.type == sfEvtMouseButtonReleased)
			CLICK_RELEASED = sfTrue;
	}
}
