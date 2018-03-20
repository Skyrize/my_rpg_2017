/*
** EPITECH PROJECT, 2017
** my_world_2017
** File description:
** main_loop.c created: 01/02/18 13:23
*/

#include "../../include/my_world.h"

void my_destroyer(ressources_t *rsces)
{
	sfTexture_destroy(rsces->textures->background);
	sfTexture_destroy(rsces->textures->dirt);
	sfTexture_destroy(rsces->textures->editing_panel);
	sfTexture_destroy(rsces->textures->grass);
	sfTexture_destroy(rsces->textures->panel);
	sfTexture_destroy(rsces->textures->stone);
	sfSound_destroy(rsces->sounds->pop);
	sfSprite_destroy(rsces->gui->background);
	sfSprite_destroy(rsces->gui->panel);
	sfSprite_destroy(rsces->gui->editing_panel);
}

void update(ressources_t *rsces)
{
	draw_map(rsces, rsces->map, rsces->window);
}

void start(ressources_t *rsces, int size)
{
	rsces->map = generate_float_map(size, size);
	rsces->cam = create_camera(0, 2.8);
	rsces->map->points_2d = malloc(sizeof(sfVector2f *) * size);
	for (int i = 0; i < size; i++)
		rsces->map->points_2d[i] = malloc(sizeof(v2f) * size);
}

void main_loop(ressources_t *rsces)
{
	sfEvent event;
	int size = start_menu(rsces);

	start(rsces, size);
	while (sfRenderWindow_isOpen(rsces->window)) {
		while (sfRenderWindow_pollEvent(rsces->window, &event))
			on_event(rsces, event);
		sfRenderWindow_clear(rsces->window, sfBlack);
		draw_background(rsces, rsces->gui);
		update(rsces);
		draw_nearest_thing(rsces);
		draw_gui(rsces, rsces->gui);
		sfRenderWindow_display(rsces->window);
	}
	sfRenderWindow_destroy(rsces->window);
	my_destroyer(rsces);
}
