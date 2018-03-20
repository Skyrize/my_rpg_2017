/*
** EPITECH PROJECT, 2017
** my_world_2017
** File description:
** map.c created: 01/02/18 17:51
*/

#include "../../../include/my_world.h"
#include <SFML/Audio.h>

float **generate_zero_float_map(v2i size)
{
	float **float_map = malloc(sizeof(float *) * (size.y + 2));

	for (int i = 0; i < size.y + 2; i ++) {
		float_map[i] = malloc(sizeof(float) * (size.x + 2));
		for (int j = 0; j < size.x + 2; j ++) {
			float_map[i][j] = 0;
		}
	}
	return (float_map);
}

map_draw_t *generate_float_map(int x, int y)
{
	float **float_map = malloc(sizeof(float *) * (y + 2));
	map_draw_t *map = malloc(sizeof(map_draw_t));

	for (int i = 0; i < y + 2; i ++) {
		float_map[i] = malloc(sizeof(float) * (x + 2));
		for (int j = 0; j < x + 2; j ++) {
			float_map[i][j] = 0;
		}
	}
	map->size = V2I(x, y);
	map->height_map = float_map;
	map->points_2d = (v2f **){0};
	return (map);
}

sfVector2f **create_2d_map(ressources_t *rsces, map_draw_t *map)
{
	sfVector2f **res = malloc(sizeof(sfVector2f *) * (map->size.y));
	float **map_fl = map->height_map;

	for (int i = 0; i < map->size.y; i++) {
		res[i] = malloc(sizeof(sfVector2f) * (map->size.x));
		for (int j = 0; j < map->size.x; j++) {
			res[i][j] = project_iso_point(rsces, \
			i * 60 - ((map->size.x - 1) / 2) * 60, \
			j * 60 - ((map->size.y - 1) / 2) * 60, \
			map_fl[i][j] * 50);
		}
	}
	return (res);
}

void free_2d_v2f_map(ressources_t *rsces, sfVector2f **map)
{
	for (int i = 0; i < rsces->map->size.y; i++) {
		free(map[i]);
	}
	free(map);
}

void render_element(ressources_t *rsces, map_draw_t *map, v2f **coords, v2i i)
{
	if (i.y == map->size.x - 1 || i.x == map->size.y - 1)
		return;
	draw_element(rsces, coords, rsces->window, i);
}
