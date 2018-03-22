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

	mode.width = 1760;
	mode.height = 990;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, "Map Editor By Lucas Sanchez",
							sfClose, NULL);
	sfRenderWindow_setFramerateLimit(window, 30);
	return (window);
}

void print_zone_coords(my_w_t *window)
{
	my_printf("zone : %d/%d\n", ZONE_COOR_X, ZONE_COOR_Y);
}

void main_loop(ressources_t *rsces, texture_list_t *list, sfVector2i area)
{
	sfEvent event;

	(void) area;
	while (sfRenderWindow_isOpen(rsces->window)) {
		while (sfRenderWindow_pollEvent(rsces->window, &event))
			on_event(rsces, event);
		sfRenderWindow_clear(rsces->window, sfWhite);
		display_map(rsces->rsces);
		draw_texture_list(list, rsces->window);
		sfRenderWindow_display(rsces->window);
	}
}

int main(int ac, char **av)
{
	ressources_t rsces;
	my_w_t window = init_my_window();
	texture_list_t *list = read_hashmap_texture(window.textures_lib);
	v2i area;

	if (ac != 4)
		return (84);
	if (!seek_zone(&window, av[1])) {
		my_printf("Zone Pas Encore Créée\n");
		return (84);
	}
	print_zone_coords(&window);
	load_my_zone(&window);
	area.x = my_getnbr(av[2]);
	area.y = my_getnbr(av[3]);
	rsces.window = my_window_create();
	rsces.rsces = &window;
	main_loop(&rsces, list, area);
	return (0);
}
