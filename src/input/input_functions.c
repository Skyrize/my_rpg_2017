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
	if (event->key.code == (sfKeyCode)window->key_player->up ||
	event->key.code == (sfKeyCode)window->key_player->up_1) {
		move_player(UP, window, false);
	}
	if (event->key.code == (sfKeyCode)window->key_player->down
	|| event->key.code == (sfKeyCode)window->key_player->down_1) {
		move_player(DOWN, window, false);
	}
	if (event->key.code == (sfKeyCode)window->key_player->left
	|| event->key.code == (sfKeyCode)window->key_player->left_1) {
		move_player(LEFT, window, false);
	}
	if (event->key.code == (sfKeyCode)window->key_player->right
	|| event->key.code == (sfKeyCode)window->key_player->right_1) {
		move_player(RIGHT, window, false);
	}
	if (event->key.code == sfKeyP)
		PLAYER_HEALTH += 1;
	else if (event->key.code == sfKeyM)
		PLAYER_HEALTH -= 1;
	if (event->key.code == sfKeyB)
		init_battle(window);
}

void analyse_events(my_w_t *window)
{
	while (sfRenderWindow_pollEvent(window->window, &window->event)) {
		if (window->event.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		if (window->event.type == sfEvtMouseButtonReleased)
			window->click_released = sfTrue;
		if (window->event.type == sfEvtKeyPressed
		&& window->key_player->move == 1)
			on_key_pressed(window, &window->event);
	}
}
