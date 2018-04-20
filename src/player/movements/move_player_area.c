/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** move_player_b.c created: 22/03/18 18:50
*/

#include <my.h>
#include <rpg.h>

bool move_player_aera_up(window_t *window, bool check)
{
	if (AREA_COOR_Y - 1 < 0)
		return (move_player_zone(UP, window, check));
	if (!(MAP.areas[AREA_COOR_Y - 1][AREA_COOR_X].name))
		return (false);
	if (check)
		return (true);
	TILE_COOR_Y = TILE_TAB_Y - 2;
	AREA_COOR_Y--;
	window->game.movement.target_tile = (sfVector2i) {TILE_COOR_X,
							  TILE_COOR_Y};
	set_initial_player_pos(window);
	return (true);
}

bool move_player_aera_down(window_t *window, bool check)
{
	if (AREA_COOR_Y + 1 > AREA_TAB_Y)
		return (move_player_zone(DOWN, window, check));
	if (!(MAP.areas[AREA_COOR_Y + 1][AREA_COOR_X].name))
		return (false);
	if (check)
		return (true);
	TILE_COOR_Y = 0;
	AREA_COOR_Y++;
	window->game.movement.target_tile = (sfVector2i) {TILE_COOR_X,
							  TILE_COOR_Y};
	set_initial_player_pos(window);
	return (true);
}

bool move_player_aera_left(window_t *window, bool check)
{
	if (AREA_COOR_X - 1 < 0)
		return (move_player_zone(LEFT, window, check));
	if (!(MAP.areas[AREA_COOR_Y][AREA_COOR_X - 1].name))
		return (false);
	if (check)
		return (true);
	TILE_COOR_X = TILE_TAB_X - 1;
	AREA_COOR_X--;
	window->game.movement.target_tile = (sfVector2i) {TILE_COOR_X,
							  TILE_COOR_Y};
	set_initial_player_pos(window);
	return (true);
}

bool move_player_aera_right(window_t *window, bool check)
{
	if (AREA_COOR_X + 1 > AREA_TAB_X)
		return (move_player_zone(RIGHT, window, check));
	if (!(MAP.areas[AREA_COOR_Y][AREA_COOR_X + 1].name))
		return (false);
	if (check)
		return (true);
	TILE_COOR_X = 0;
	AREA_COOR_X++;
	window->game.movement.target_tile = (sfVector2i) {TILE_COOR_X,
							  TILE_COOR_Y};
	set_initial_player_pos(window);
	return (true);
}

bool move_player_area(direction_t dir, window_t *window, bool check)
{
	switch (dir) {
		case UP:
			return (move_player_aera_up(window, check));
		case DOWN:
			return (move_player_aera_down(window, check));
		case LEFT:
			return (move_player_aera_left(window, check));
		case RIGHT:
			return (move_player_aera_right(window, check));
	}
	return (false);
}