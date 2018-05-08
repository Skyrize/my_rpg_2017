/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** lobby.c
*/

#include <SFML/Window/Event.h>
#include "rpg.h"

int on_key_pressed(game_t *game, sfEvent *event)
{
	game->movement.is_moving = sfFalse;
	if (sfKeyboard_isKeyPressed(KEY_UP) == sfTrue
	|| sfKeyboard_isKeyPressed(ARROW_KEY_UP) == sfTrue)
		move_player(UP, game);
	if (sfKeyboard_isKeyPressed(KEY_DOWN) == sfTrue
	|| sfKeyboard_isKeyPressed(ARROW_KEY_DOWN) == sfTrue)
		move_player(DOWN, game);
	if (sfKeyboard_isKeyPressed(KEY_LEFT) == sfTrue
	|| sfKeyboard_isKeyPressed(ARROW_KEY_LEFT) == sfTrue)
		move_player(LEFT, game);
	if (sfKeyboard_isKeyPressed(KEY_RIGHT) == sfTrue
	|| sfKeyboard_isKeyPressed(ARROW_KEY_RIGHT) == sfTrue)
		move_player(RIGHT, game);
	if (event->key.code == sfKeyP)
		PLAYER_HEALTH += 1;
	else if (event->key.code == sfKeyM)
		PLAYER_HEALTH -= 1;
	if (event->key.code == sfKeyO)
		PLAYER_XP += 1;
	else if (event->key.code == sfKeyL)
		PLAYER_XP -= 1;
	return (0);
}

int press_action_key(game_t *game)
{
	static sfBool pass = sfTrue;
	static sfBool music = sfTrue;

	if (pass == sfTrue) {
		if (process_npc_dialogue(game) != 0)
			return (84);
		if (music == sfTrue) {
			make_sound("DIALOGUE_SOUND", game);
			music = sfFalse;
		} else
			music = sfTrue;
		if (button_display_hide_scene("DIALOGUE_HUD", NULL,
		game, "GAME") == 84)
			return (84);
		CURRENT_BUCKET = hm_get_bucket(SCENES, "GAME");
		pass = sfFalse;
	} else
		pass = sfTrue;
	return (0);
}

int game_events(window_t *window, game_t *game)
{
	if (window->event.type == sfEvtClosed)
		sfRenderWindow_close(window->window);
	if (window->event.type == sfEvtMouseButtonReleased)
		CLICK_RELEASED = sfTrue;
	if (window->event.type == sfEvtKeyPressed
	&& KEY_PLAYER.move == 1)
		on_key_pressed(game, &window->event);
	if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
		if (press_action_key(game) != 0)
			return (84);
	return (0);
}

int game_lobby(window_t *window, game_t *game)
{
	int my_errno = check_step_to_battle(game);

	if (my_errno != 0)
		return (my_errno);
	rain(game, window);
	display_particles(window, game);
	if (manage_life(game) != 0
	|| change_area_hud(game) != 0
	|| anim_player(game) != 0
	|| manage_hud_opacity(game) != 0)
		return (84);
	smooth_move_player(game);
	return (0);
}