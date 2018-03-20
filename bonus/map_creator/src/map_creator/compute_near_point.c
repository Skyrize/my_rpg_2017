/*
** EPITECH PROJECT, 2017
** my_world_2017
** File description:
** compute_near_point
*/

#include "../../include/my_world.h"

int compute_point(v2f vector, v2i mouse, float *diff)
{
	v2f diff_point = V2F(0, 0);;

	if (vector.y > mouse.y)
		diff_point.y = vector.y - mouse.y;
	else
		diff_point.y = mouse.y - vector.y;
	if (vector.x > mouse.x)
		diff_point.x = vector.x - mouse.x;
	else
		diff_point.x = mouse.x - vector.x;
	if (diff_point.x + diff_point.y < *diff) {
		*diff = diff_point.x + diff_point.y;
		return (1);
	}
	return (0);
}

v2i find_point_on_line(ressources_t *rsces, v2i mouse_pos, float *diff, int i)
{
	v2i point;

	for (int j = 0; j < rsces->map->size.y; j++) {
		if (compute_point(rsces->map->points_2d[i][j],
		mouse_pos, diff) == 1)
			point = V2I(i, j);
	}
	return (point);
}

v2i find_point(ressources_t *rsces, v2i mouse_pos)
{
	float diff = 10000000;
	v2i point;

	for (int i = 0; i < rsces->map->size.x; i++) {
		point = find_point_on_line(rsces, mouse_pos, &diff, i);
	}
	return (point);
}
