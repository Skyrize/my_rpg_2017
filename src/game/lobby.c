/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** lobby.c
*/

#include <SFML/Window/Event.h>
#include "rpg.h"

void on_key_pressed(game_t *game, sfEvent *event)
{
	if (sfKeyboard_isKeyPressed(KEY_UP) == sfTrue
	|| sfKeyboard_isKeyPressed(ARROW_KEY_UP) == sfTrue) {
		move_player(UP, game, false);
	}
	if (sfKeyboard_isKeyPressed(KEY_DOWN) == sfTrue
	|| sfKeyboard_isKeyPressed(ARROW_KEY_DOWN) == sfTrue) {
		move_player(DOWN, game, false);
	}
	if (sfKeyboard_isKeyPressed(KEY_LEFT) == sfTrue
	|| sfKeyboard_isKeyPressed(ARROW_KEY_LEFT) == sfTrue) {
		move_player(LEFT, game, false);
	}
	if (sfKeyboard_isKeyPressed(KEY_RIGHT) == sfTrue
	|| sfKeyboard_isKeyPressed(ARROW_KEY_RIGHT) == sfTrue) {
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