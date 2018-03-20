/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** draw_nearest_thing
*/

#include "../../include/my_world.h"

sfVertexArray *create_tile(v2f *p_1, v2f *p_2, v2f *p_3, v2f *p_4)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = *p_1,
		.color = (sfColor){255, 0, 0, 128}, .texCoords = V2F(0, 0)};
	sfVertex vertex2 = {.position = *p_2,
		.color = (sfColor){255, 0, 0, 128}, .texCoords = V2F(0, 16)};
	sfVertex vertex3 = {.position = *p_3,
		.color = (sfColor){255, 0, 0, 128}, .texCoords = V2F(16, 16)};
	sfVertex vertex4 = {.position = *p_4,
		.color = (sfColor){255, 0, 0, 128}, .texCoords = V2F(16, 0)};

	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_append(vertex_array, vertex3);
	sfVertexArray_append(vertex_array, vertex4);
	sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
	return (vertex_array);
}

void draw_near_tile(ressources_t *rsces)
{
	tile_coord_t nearest_tile = compute_near_tile(rsces);
	v2f **map = rsces->map->points_2d;
	v2f p_1 = map[nearest_tile.first_point.x][nearest_tile.first_point.y];
	v2f p_2 = map[nearest_tile.second_point.x][nearest_tile.second_point.y];
	v2f p_3 = map[nearest_tile.third_point.x][nearest_tile.third_point.y];
	v2f p_4 = map[nearest_tile.fourth_point.x][nearest_tile.fourth_point.y];
	sfVertexArray *tile = create_tile(&p_1, &p_2, &p_4, &p_3);

	rsces->map->selected_tile = nearest_tile;
	sfRenderWindow_drawVertexArray(rsces->window, tile, NULL);
	sfVertexArray_destroy(tile);
}

void draw_near_point(ressources_t *rsces)
{
	sfCircleShape *near_point = sfCircleShape_create();
	v2i mouse_pos = sfMouse_getPositionRenderWindow(rsces->window);
	v2f point_pos;
	v2i point_pos_in_tab;

	point_pos_in_tab = find_point(rsces, mouse_pos);
	point_pos.x =
		rsces->map->points_2d[point_pos_in_tab.x][point_pos_in_tab.y].x;
	point_pos.y =
		rsces->map->points_2d[point_pos_in_tab.x][point_pos_in_tab.y].y;
	rsces->map->selected_point = point_pos_in_tab;
	sfCircleShape_setPosition(near_point, point_pos);
	sfCircleShape_setFillColor(near_point, sfRed);
	sfCircleShape_setRadius(near_point, 3);
	sfCircleShape_setOrigin(near_point, V2F(1.5, 1.5));
	sfRenderWindow_drawCircleShape(rsces->window, near_point, NULL);
	sfCircleShape_destroy(near_point);
}

void draw_nearest_thing(ressources_t *rsces)
{
	if (rsces->gui->mode == 1)
		draw_near_point(rsces);
	else if (rsces->gui->mode == 2)
		draw_near_tile(rsces);
}
