/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** lobby.c
*/

#include <SFML/Window/Event.h>
#include "rpg.h"

///mettre ici les évènements relatifs à GAME

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

int game_events(window_t *window, game_t *game)
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
	return (0);
}

int game_lobby(window_t *window, game_t *game)
{
	if (game_events(window, game)
	|| manage_life(game) != 0
	|| change_area_hud(game) != 0
	|| anim_player(game) != 0
	|| manage_hud_opacity(game) != 0)
		return (84);
	smooth_move_player(game);
	return (0);
}