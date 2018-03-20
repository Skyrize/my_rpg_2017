/*
** EPITECH PROJECT, 2017
** my_world_2017
** File description:
** render.c created: 01/02/18 17:37
*/

#include <math.h>
#include "../../../include/my_world.h"

sfVertexArray *create_line(v2f *point_1, v2f *point_2,
			   sfColor color)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = *point_1, .color = color};
	sfVertex vertex2 = {.position = *point_2, .color = color};

	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
	return (vertex_array);
}

sfVertexArray *create_poly(v2f *p_1, v2f *p_2, v2f *p_3, v2f *p_4)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = *p_1, .color = sfWhite,
		.texCoords = V2F(0, 0)};
	sfVertex vertex2 = {.position = *p_2, .color = sfWhite,
		.texCoords = V2F(0, 16)};
	sfVertex vertex3 = {.position = *p_3, .color = sfWhite,
		.texCoords = V2F(16, 16)};
	sfVertex vertex4 = {.position = *p_4, .color = sfWhite,
		.texCoords = V2F(16, 0)};

	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_append(vertex_array, vertex3);
	sfVertexArray_append(vertex_array, vertex4);
	sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
	return (vertex_array);
}

sfVector2f project_iso_point(ressources_t *rsces, float x, float y, float z)
{
	sfVector2f point;
	double x_angle = rsces->cam->x;
	double y_angle = rsces->cam->y;

	point.x = (float) ((x) * cos(x_angle) - y * sin(x_angle))
							* rsces->cam->scale.x;
	point.y = (float) ((x) * sin(x_angle) + y * cos(x_angle))
							* rsces->cam->scale.y;
	point.y = (float) ((point.y) * sin(y_angle) + z * cos(y_angle)
							* rsces->cam->scale.x);
	point.x += rsces->mode.width / 2;
	point.y += rsces->mode.height / 2;
	return (point);
}

void draw_element(ressources_t *rsces, sfVector2f **coords,
		  sfRenderWindow *window, sfVector2i v)
{
	sfRenderWindow_drawVertexArray(window, \
	create_poly(&coords[v.x][v.y], &coords[v.x + 1][v.y], \
	&coords[v.x + 1][v.y + 1], &coords[v.x][v.y + 1]), \
	create_state(rsces->textures->grass));
	if (rsces->gui->grid == 0)
		return;
	sfRenderWindow_drawVertexArray(window, \
	create_line(&coords[v.x][v.y], &coords[v.x + 1][v.y], \
	sfWhite), NULL);
	sfRenderWindow_drawVertexArray(window, \
	create_line(&coords[v.x][v.y], &coords[v.x][v.y + 1], \
	sfWhite), NULL);
	sfRenderWindow_drawVertexArray(window, \
	create_line(&coords[v.x + 1][v.y], &coords[v.x + 1][v.y + 1], \
	sfWhite), NULL);
	sfRenderWindow_drawVertexArray(window, \
	create_line(&coords[v.x][v.y + 1], &coords[v.x + 1][v.y + 1], \
	sfWhite), NULL);
}

void draw_map(ressources_t *rsces, map_draw_t *map, sfRenderWindow *window)
{
	sfVector2f **coords = create_2d_map(rsces, map);

	for (int i = 0; i < map->size.x; i++) {
		for (int j = 0; j < map->size.y; j++)
			map->points_2d[i][j] = coords[i][j];
	}
	draw_with_rotation(rsces, coords, map);
	free_2d_v2f_map(rsces, coords);
}
