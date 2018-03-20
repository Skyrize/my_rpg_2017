/*
** EPITECH PROJECT, 2017
** my_world_2017
** File description:
** window.c created: 01/02/18 13:18
*/

#include "../../include/my_world.h"
#include <SFML/Window.h>

sfRenderWindow *create_window(ressources_t *rsces)
{
	sfVideoMode mode = {1600, 900, 32};
	sfRenderWindow *window;
	sfContextSettings setting;

	setting.antialiasingLevel = 16;
	setting.majorVersion = 3;
	setting.depthBits = 24;
	setting.stencilBits = 8;
	window = sfRenderWindow_create(mode, "World Editor",
				       sfClose, &setting);
	rsces->window = window;
	rsces->mode = mode;
	return (window);
}
