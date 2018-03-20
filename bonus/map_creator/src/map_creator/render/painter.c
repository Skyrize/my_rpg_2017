/*
** EPITECH PROJECT, 2017
** my_world_2017
** File description:
** U know da problem
*/

#include "../../../include/my_world.h"

void render_rot_a(ressources_t *rsces, map_draw_t *map, sfVector2f **coords)
{
	for (int i = 0; i < map->size.y; i++)
		for (int j = 0; j < map->size.x ; j++)
			render_element(rsces, map, coords, V2I(i, j));
}

void render_rot_b(ressources_t *rsces, map_draw_t *map, sfVector2f **coords)
{
	for (int j = map->size.x - 1; j >= 0; j--)
		for (int i = 0; i < map->size.y ; i++)
			render_element(rsces, map, coords, V2I(i, j));
}

void render_rot_c(ressources_t *rsces, map_draw_t *map, sfVector2f **coords)
{
	for (int j = map->size.x - 1; j >= 0; j--)
		for (int i = map->size.y - 1; i >= 0 ; i--)
			render_element(rsces, map, coords, V2I(i, j));
}

void render_rot_d(ressources_t *rsces, map_draw_t *map, sfVector2f **coords)
{
	for (int j = 0; j < map->size.x; j++)
		for (int i = map->size.y - 1; i >= 0 ; i--)
			render_element(rsces, map, coords, V2I(i, j));
}

void draw_with_rotation(ressources_t *rsces, sfVector2f **coords, map_draw_t *map)
{
	float x = rsces->cam->x;

	if (x < 1.6)
		render_rot_a(rsces, map, coords);
	else if (x < 3)
		render_rot_b(rsces, map, coords);
	else if (x < 4.7)
		render_rot_c(rsces, map, coords);
	else
		render_rot_d(rsces, map, coords);
}
