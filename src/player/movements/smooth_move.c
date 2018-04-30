/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** smooth_move.c created: 18/04/18
*/

#include <rpg.h>
#include <SFML/Audio.h>

void set_initial_player_pos(game_t *game)
{
	sfRectangleShape_setPosition(game->player.character->obj, \
	(sfVector2f) {TILE_COOR_X * 50, TILE_COOR_Y * 50});
}

bool is_pressing_controls(game_t *game)
{
	if (KEY_PRESSED(left) || KEY_PRESSED(left_1) || KEY_PRESSED(right) ||
	KEY_PRESSED(right_1) || KEY_PRESSED(up) || KEY_PRESSED(up_1) ||
	KEY_PRESSED(down) || KEY_PRESSED(down_1))
		return (true);
	return (false);
}

void is_waiting(game_t *game)
{
	if (!is_pressing_controls(game))
		set_waiting_player_rect(game);
}

//TODO norme
//call every frames
void smooth_move_player(game_t *game)
{
	sfVector2i act_pos = MAP.tile_coord;
	sfVector2i *target_pos = &(game->movement.target_tile);
	sfVector2f s_pos;
	sfVector2f offset_f = (sfVector2f) {(target_pos->x - act_pos.x) * 5,
					(target_pos->y - act_pos.y) * 5};
	static bool is_check = false;

	if (my_strcmp(CURRENT_SCENE->key, "GAME") != 0)
		return;
	if (!(game->player.character))
		return;
	if (!is_check) {
		set_initial_player_pos(game);
		is_check = true;
	}
	s_pos = sfRectangleShape_getPosition(PLAYER.character->obj);
	if (!game->player.character->obj_rect.animated)
		return;
	if (s_pos.x == target_pos->x * 50 && s_pos.y == target_pos->y * 50) {
		TILE_COOR_X = target_pos->x;
		TILE_COOR_Y = target_pos->y;
		game->player.character->obj_rect.animated = sfFalse;
		is_waiting(game);
		return;
	}
	if (act_pos.x == target_pos->x && act_pos.y == target_pos->y)
		return;
	sfRectangleShape_move(PLAYER.character->obj, offset_f);
}