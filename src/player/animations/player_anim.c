/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** player animation handling
*/

#include <rpg.h>
#include <SFML/System/Time.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Audio.h>

void set_next_rect_b(window_t *window)
{
	int mult = window->game.movement.anim_mult;

	PLAYER.character->obj_rect.rect.left +=
		(mult * PLAYER.character->obj_rect.rect_offset.x);
	PLAYER.character->obj_rect.rect.top +=
		(mult * PLAYER.character->obj_rect.rect_offset.y);
}

void set_next_rect(window_t *window)
{
	int act_x;
	int act_y;
	int mult = window->game.movement.anim_mult;

	set_next_rect_b(window);
	act_y = PLAYER.character->obj_rect.rect.top;
	act_x = PLAYER.character->obj_rect.rect.left;
	if (act_x >= PLAYER.character->obj_rect.rect_max.x ||
	    act_y > PLAYER.character->obj_rect.rect_max.y ||
	    act_x <= PLAYER.character->obj_rect.rect_start.x ||
	    act_y < PLAYER.character->obj_rect.rect_start.y) {
		window->game.movement.anim_mult = -1 * mult;
	}
	sfRectangleShape_setTextureRect(
		window->game.player.character->obj,
		window->game.player.character->obj_rect.rect);
}

void set_anim_side(window_t *window)
{
	PLAYER.character->obj_rect.rect.top =
		PLAYER.character->obj_rect.rect_start.y;
	sfRectangleShape_setTextureRect(
		window->game.player.character->obj,
		window->game.player.character->obj_rect.rect);
}

void set_waiting_player_rect(window_t *window)
{
	PLAYER.character->obj_rect.rect.top =
		PLAYER.character->obj_rect.rect_start.y;
	PLAYER.character->obj_rect.rect.left = 50;
	sfRectangleShape_setTextureRect(
		window->game.player.character->obj,
		window->game.player.character->obj_rect.rect);
}

//call on every frames
void anim_player(window_t *window)
{
	static sfClock *clock = NULL;

	update_moving_state(window);
	if (strcmp(CURRENT_SCENE->key, "GAME") != 0)
		return;
	if (!(window->game.player.character))
		return;
	if (!window->game.player.character->obj_rect.animated)
		return;
	if (!clock)
		clock = sfClock_create();
	if (sfClock_getElapsedTime(clock).microseconds > 100000) {
		sfClock_restart(clock);
		set_next_rect(window);
	}
}