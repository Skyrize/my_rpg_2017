/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** move_player.c created: 22/03/18 18:31
*/

#include <my.h>
#include <rpg.h>
#include <SFML/Graphics/Rect.h>

bool move_player_up(window_t *window, bool check)
{
	if (!check) {
		window->game.player.character->obj_rect.rect_start.x = 0;
		window->game.player.character->obj_rect.rect_start.y = 300;
		window->game.player.character->obj_rect.rect_max.x = 100;
		window->game.player.character->obj_rect.rect_max.y = 300;
		window->game.player.character->obj_rect.rect_offset.x = 50;
		window->game.player.character->obj_rect.rect_offset.y = 0;
		window->game.player.character->obj_rect.animated = sfTrue;
		set_anim_side(window);
	}
	if (TILE_COOR_Y - 1 <= -1)
		return (move_player_area(UP, window, check));
	if (AREA.tiles[TILE_COOR_Y][TILE_COOR_X].block)
		return (false);
	if (check)
		return (true);
	window->game.movement.target_tile = (sfVector2i) {TILE_COOR_X,
							  TILE_COOR_Y - 1};
	return (true);
}

bool move_player_down(window_t *window, bool check)
{
	if (!check) {
		window->game.player.character->obj_rect.rect_start.x = 0;
		window->game.player.character->obj_rect.rect_start.y = 0;
		window->game.player.character->obj_rect.rect_max.x = 100;
		window->game.player.character->obj_rect.rect_max.y = 0;
		window->game.player.character->obj_rect.rect_offset.x = 50;
		window->game.player.character->obj_rect.rect_offset.y = 0;
		window->game.player.character->obj_rect.animated = sfTrue;
		set_anim_side(window);
	}
	if (TILE_COOR_Y + 1 > TILE_TAB_Y - 2)
		return (move_player_area(DOWN, window, check));
	if (AREA.tiles[TILE_COOR_Y + 2][TILE_COOR_X].block)
		return (false);
	if (check)
		return (true);
	window->game.movement.target_tile = (sfVector2i) {TILE_COOR_X,
							  TILE_COOR_Y + 1};
	return (true);
}

bool move_player_left(window_t *window, bool check)
{
	if (!check) {
		window->game.player.character->obj_rect.rect_start.x = 0;
		window->game.player.character->obj_rect.rect_start.y = 100;
		window->game.player.character->obj_rect.rect_max.x = 100;
		window->game.player.character->obj_rect.rect_max.y = 100;
		window->game.player.character->obj_rect.rect_offset.x = 50;
		window->game.player.character->obj_rect.rect_offset.y = 0;
		window->game.player.character->obj_rect.animated = sfTrue;
		set_anim_side(window);
	}
	if (TILE_COOR_X - 1 <= -1)
		return (move_player_area(LEFT, window, check));
	if (AREA.tiles[TILE_COOR_Y + 1][TILE_COOR_X - 1].block)
		return (false);
	if (check)
		return (true);
	window->game.movement.target_tile = (sfVector2i) {TILE_COOR_X - 1,
							  TILE_COOR_Y};
	return (true);
}

bool move_player_right(window_t *window, bool check)
{
	if (!check) {
		window->game.player.character->obj_rect.rect_start.x = 0;
		window->game.player.character->obj_rect.rect_start.y = 200;
		window->game.player.character->obj_rect.rect_max.x = 100;
		window->game.player.character->obj_rect.rect_max.y = 200;
		window->game.player.character->obj_rect.rect_offset.x = 50;
		window->game.player.character->obj_rect.rect_offset.y = 0;
		window->game.player.character->obj_rect.animated = sfTrue;
		set_anim_side(window);
	}
	if (TILE_COOR_X + 1 > TILE_TAB_X - 1)
		return (move_player_area(RIGHT, window, check));
	if (AREA.tiles[TILE_COOR_Y + 1][TILE_COOR_X + 1].block)
		return (false);
	if (check)
		return (true);
	window->game.movement.target_tile = (sfVector2i) {TILE_COOR_X + 1,
							  TILE_COOR_Y};
	return (true);
}

bool move_player(direction_t dir, window_t *window, bool check)
{
	if (my_strcmp(CURRENT_SCENE->key, "GAME") != 0)
		return (false);
	if (window->game.player.character->obj_rect.animated)
		return (false);
	switch (dir) {
		case UP:
			return (move_player_up(window, check));
		case DOWN:
			return (move_player_down(window, check));
		case LEFT:
			return (move_player_left(window, check));
		case RIGHT:
			return (move_player_right(window, check));
	}
	return (false);
}
