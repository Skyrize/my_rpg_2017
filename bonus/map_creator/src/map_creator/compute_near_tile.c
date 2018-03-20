/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** ompute_near_tile.
*/

#include "../../include/my_world.h"

v2i find_second_point(v2i mouse_pos, v2i nearest_pos, v2f **map)
{
	float diff_one = 0;
	float diff_two = 0;

	diff_one = absolute_value(mouse_pos.x -
		map[nearest_pos.x - 1][nearest_pos.y].x)
		+ absolute_value(mouse_pos.y -
		map[nearest_pos.x - 1][nearest_pos.y].y);
	diff_two = absolute_value(mouse_pos.x -
		map[nearest_pos.x + 1][nearest_pos.y].x)
		+ absolute_value(mouse_pos.y -
		map[nearest_pos.x + 1][nearest_pos.y].y);
	if (diff_one > diff_two)
		return (V2I(nearest_pos.x + 1, nearest_pos.y));
	return (V2I(nearest_pos.x - 1, nearest_pos.y));
}

v2i find_third_point(v2i mouse_pos, v2i nearest_pos, v2f **map)
{
	float diff_one = 0;
	float diff_two = 0;

	diff_one = absolute_value(mouse_pos.x -
		map[nearest_pos.x][nearest_pos.y - 1].x)
		+ absolute_value(mouse_pos.y -
		map[nearest_pos.x][nearest_pos.y - 1].y);
	diff_two = absolute_value(mouse_pos.x -
		map[nearest_pos.x][nearest_pos.y + 1].x)
		+ absolute_value(mouse_pos.y -
		map[nearest_pos.x][nearest_pos.y + 1].y);
	if (diff_one > diff_two)
		return (V2I(nearest_pos.x, nearest_pos.y + 1));
	return (V2I(nearest_pos.x, nearest_pos.y - 1));
}

v2i compute_fourth_point(v2i first_point, v2i second_point, v2i third_point)
{
	v2i fourth_point;

	fourth_point.x = first_point.x + (second_point.x - first_point.x);
	fourth_point.y = first_point.y + (third_point.y - first_point.y);
	return (fourth_point);
}

void compute_second_and_third_point(v2i nearest_pos, ressources_t *rsces,
						v2i mouse_pos, tile_coord_t *tile)
{
	v2f **map = rsces->map->points_2d;

	if (nearest_pos.x == 0) {
		tile->third_point = find_third_point(mouse_pos,
							nearest_pos, map);
		tile->second_point = V2I(nearest_pos.x + 1, nearest_pos.y);
	} else if (nearest_pos.x == rsces->map->size.x - 1) {
		tile->third_point = find_third_point(mouse_pos,
							nearest_pos, map);
		tile->second_point = V2I(nearest_pos.x - 1, nearest_pos.y);
	} else {
		tile->second_point = find_second_point(mouse_pos,
							nearest_pos, map);
		tile->third_point = find_third_point(mouse_pos,
							nearest_pos, map);
	}
	if (tile->third_point.y < 0)
		tile->third_point.y = 1;
}

tile_coord_t compute_near_tile(ressources_t *rsces)
{
	v2i mouse_pos = sfMouse_getPositionRenderWindow(rsces->window);
	v2i nearest_pos = find_point(rsces, mouse_pos);
	tile_coord_t tile;

	tile.first_point = nearest_pos;
	compute_second_and_third_point(nearest_pos, rsces, mouse_pos, &tile);
	tile.fourth_point = compute_fourth_point(nearest_pos,
					tile.second_point, tile.third_point);
	return (tile);
}
