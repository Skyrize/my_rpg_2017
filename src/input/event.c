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
void on_key_pressed(game_t *game, sfEvent *event)
{
	if (event->key.code == (sfKeyCode)KEY_PLAYER.up ||
	event->key.code == (sfKeyCode)KEY_PLAYER.up_1) {
		move_player(UP, game, false);
	}
	if (event->key.code == (sfKeyCode)KEY_PLAYER.down
	|| event->key.code == (sfKeyCode)KEY_PLAYER.down_1) {
		move_player(DOWN, game, false);
	}
	if (event->key.code == (sfKeyCode)KEY_PLAYER.left
	|| event->key.code == (sfKeyCode)KEY_PLAYER.left_1) {
		move_player(LEFT, game, false);
	}
	if (event->key.code == (sfKeyCode)KEY_PLAYER.right
	|| event->key.code == (sfKeyCode)KEY_PLAYER.right_1) {
		move_player(RIGHT, game, false);
	}
	if (event->key.code == sfKeyP)
		PLAYER_HEALTH += 1;
	else if (event->key.code == sfKeyM)
		PLAYER_HEALTH -= 1;
}

void analyse_events(window_t *window, game_t *game)
{
	while (sfRenderWindow_pollEvent(window->window, &window->event)) {
		if (window->event.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		if (window->event.type == sfEvtMouseButtonReleased)
			CLICK_RELEASED = sfTrue;
		if (window->event.type == sfEvtKeyPressed
		&& KEY_PLAYER.move == 1)
			on_key_pressed(game, &window->event);
	}
}
