/*
** EPITECH PROJECT, 2017
** delivery
** File description:
** delivery made by Sanchez Lucas
*/

#include "map_editor.h"

sfRenderWindow *my_window_create()
{
	sfRenderWindow *window;
	sfVideoMode mode;

	mode.width = 1600;
	mode.height = 900;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, "Map Editor By Lucas Sanchez",
							sfClose, NULL);
	sfRenderWindow_setFramerateLimit(window, 30);
	return (window);
}

void main_loop(ressources_t *rsces, sfVector2i area)
{
	sfEvent event;

	while (sfRenderWindow_isOpen(rsces->window)) {
		while (sfRenderWindow_pollEvent(rsces->window, &event))
			on_event(rsces, event);
		sfRenderWindow_clear(rsces->window, sfBlack);
		sfRenderWindow_display(rsces->window);
	}
}

int main(int ac, char **av)
{
	sfRenderWindow *window = my_window_create();
	ressources_t rsces;
	my_w_t my_window = init_my_window();
	v2i area;

	if (ac != 3)
		return (84);
	area = area_selector();
	rsces.window = window;
	rsces.rsces = &my_window;
	main_loop(&rsces, area);
	return (0);
}
