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
		move_player(UP, game);
	}
	if (sfKeyboard_isKeyPressed(KEY_DOWN) == sfTrue
	|| sfKeyboard_isKeyPressed(ARROW_KEY_DOWN) == sfTrue) {
		move_player(DOWN, game);
	}
	if (sfKeyboard_isKeyPressed(KEY_LEFT) == sfTrue
	|| sfKeyboard_isKeyPressed(ARROW_KEY_LEFT) == sfTrue) {
		move_player(LEFT, game);
	}
	if (sfKeyboard_isKeyPressed(KEY_RIGHT) == sfTrue
	|| sfKeyboard_isKeyPressed(ARROW_KEY_RIGHT) == sfTrue) {
		move_player(RIGHT, game);
	}
	if (event->key.code == sfKeyP)
		PLAYER_HEALTH += 1;
	else if (event->key.code == sfKeyM)
		PLAYER_HEALTH -= 1;
}

int press_action_key(game_t *game)
{
	static sfBool pass = sfTrue;
	static sfBool music = sfTrue;

	// check_special_tiles_around();
	if (pass == sfTrue) {
		if (music == sfTrue) {
			make_sound("DIALOGUE_SOUND", game);
			music = sfFalse;
		} else {
			music = sfTrue;
		}
		if (button_display_hide_scene("DIALOGUE_HUD", NULL, game) == 84)
			return (84);
		pass = sfFalse;
	} else {
		pass = sfTrue;
	}
	return (0);
}

int game_events(window_t *window, game_t *game)
{
	int my_errno = 0;

	while (sfRenderWindow_pollEvent(window->window, &window->event)) {
		if (window->event.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		if (window->event.type == sfEvtMouseButtonReleased)
			CLICK_RELEASED = sfTrue;
		if (window->event.type == sfEvtKeyPressed
		&& KEY_PLAYER.move == 1)
			on_key_pressed(game, &window->event);
		if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue) {
			my_errno = press_action_key(game);
		}
		if (my_errno == 84)
			return (my_errno);
	}
	return (0);
}

int game_lobby(window_t *window, game_t *game)
{
	rain(game, window);
	if (game_events(window, game)
	|| manage_life(game) != 0
	|| change_area_hud(game) != 0
	|| anim_player(game) != 0
	    || (display_particles(window, game), false)
	|| manage_hud_opacity(game) != 0)
		return (84);
	smooth_move_player(game);
	return (0);
}