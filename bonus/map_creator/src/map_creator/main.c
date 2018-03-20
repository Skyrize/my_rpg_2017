/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** main.c
*/

#include "../../include/my_world.h"
#include <SFML/Window.h>

void init(ressources_t *rsces)
{
	create_textures(rsces);
	create_sounds(rsces);
	create_gui(rsces);
	sfRenderWindow_setFramerateLimit(rsces->window, 30);
	main_loop(rsces);
}

int main(int ac, char *av[])
{
	ressources_t *rsces = create_ressources();

	init(rsces);
	return (0);
}
