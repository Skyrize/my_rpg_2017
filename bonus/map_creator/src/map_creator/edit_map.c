/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** edit_map
*/

#include "../../include/my_world.h"

void edit_map_point(ressources_t *rsces)
{
	int x = rsces->map->selected_point.x;
	int y = rsces->map->selected_point.y;

	if (sfKeyboard_isKeyPressed(sfKeyA))
		rsces->map->height_map[x][y] += 0.2;
	else if (sfKeyboard_isKeyPressed(sfKeyQ))
		rsces->map->height_map[x][y] -= 0.2;
}

void edit_map_tile(ressources_t *rsces)
{
	int x_1 = rsces->map->selected_tile.first_point.x;
	int y_1 = rsces->map->selected_tile.first_point.y;
	int x_2 = rsces->map->selected_tile.second_point.x;
	int y_2 = rsces->map->selected_tile.second_point.y;
	int x_3 = rsces->map->selected_tile.third_point.x;
	int y_3 = rsces->map->selected_tile.third_point.y;
	int x_4 = rsces->map->selected_tile.fourth_point.x;
	int y_4 = rsces->map->selected_tile.fourth_point.y;

	if (sfKeyboard_isKeyPressed(sfKeyA)) {
		rsces->map->height_map[x_1][y_1] += 0.2;
		rsces->map->height_map[x_2][y_2] += 0.2;
		rsces->map->height_map[x_3][y_3] += 0.2;
		rsces->map->height_map[x_4][y_4] += 0.2;
	} else if (sfKeyboard_isKeyPressed(sfKeyQ)) {
		rsces->map->height_map[x_1][y_1] -= 0.2;
		rsces->map->height_map[x_2][y_2] -= 0.2;
		rsces->map->height_map[x_3][y_3] -= 0.2;
		rsces->map->height_map[x_4][y_4] -= 0.2;
	}
}
