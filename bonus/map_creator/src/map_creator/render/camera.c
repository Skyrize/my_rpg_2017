/*
** EPITECH PROJECT, 2017
** my_world_2017
** File description:
** camera.c created: 01/02/18 19:10
*/

#include "../../../include/my_world.h"

camera_t *create_camera(float x, float y)
{
	camera_t *cam = malloc(sizeof(camera_t));

	cam->x = x;
	cam->y = y;
	cam->scale = V2F(1, 1);
	return (cam);
}
