/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** smooth_move.c created: 18/04/18
*/

#include <rpg.h>
#include <SFML/Audio.h>

void init_movements(my_w_t *window)
{
	window->game.movement.target_tile = (sfVector2i) {0, 0};
	window->game.movement.anim_mult = 1;
	window->game.movement.is_moving = false;
}

void set_initial_player_pos(my_w_t *window)
{
	sfRectangleShape_setPosition(window->game.player.character->obj, \
	(sfVector2f) {TILE_COOR_X * 50, TILE_COOR_Y * 50});
}

bool is_pressing_controls(my_w_t *window)
{
	if (KEY_PRESSED(left) || KEY_PRESSED(left_1) || KEY_PRESSED(right) ||
	    KEY_PRESSED(right_1) || KEY_PRESSED(up) || KEY_PRESSED(up_1) ||
	    KEY_PRESSED(down) || KEY_PRESSED(down_1))
		return (true);
	return (false);
}

void is_waiting(my_w_t *window)
{
	if (!is_pressing_controls(window))
		set_waiting_player_rect(window);
}

//TODO norme
//call every frames
void smooth_move_player(my_w_t *window)
{
	sfVector2i act_pos = window->map.tile_coord;
	sfVector2i *target_pos = &(window->game.movement.target_tile);
	sfVector2f s_pos;
	sfVector2f offset_f = (sfVector2f) {(target_pos->x - act_pos.x) * 2,
					    (target_pos->y - act_pos.y) * 2};
	static bool is_check = false;

	if (my_strcmp(window->current->key, "GAME") != 0)
		return;
	if (!(window->game.player.character))
		return;
	if (!is_check) {
		set_initial_player_pos(window);
		is_check = true;
	}
	s_pos = sfRectangleShape_getPosition(PLAYER.character->obj);
	if (!window->game.player.character->obj_rect.animated)
		return;
	if (s_pos.x == target_pos->x * 50 && s_pos.y == target_pos->y * 50) {
		TILE_COOR_X = target_pos->x;
		TILE_COOR_Y = target_pos->y;
		window->game.player.character->obj_rect.animated = sfFalse;
		is_waiting(window);
		return;
	}
	if (act_pos.x == target_pos->x && act_pos.y == target_pos->y)
		return;
	sfRectangleShape_move(PLAYER.character->obj, offset_f);
}