/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int display_tiles(int x, int y, int priority, window_t *window)
{
	tile_list_t *tmp = AREA.tiles[y][x].displayed_tiles;

	if (check_invalid_tile_display(tmp, x, y, window) != 0)
		return (84);
	while (tmp) {
		if (tmp->tile->priority == priority) {
			sfRenderWindow_drawRectangleShape(window->window,
				tmp->tile->obj, NULL);
			time_animation(tmp->tile, 0.1, window);
		}
		tmp = tmp->next;
	}
	if (priority == 3)
		sfRenderWindow_drawRectangleShape(window->window,
			window->game.player.character->obj, NULL);
	return (0);
}

int display_area(int priority, window_t *window)
{
	for (int y = 0; y != TILE_TAB_Y; y++) {
		for (int x = 0; x != TILE_TAB_X; x++)
			window->error_no += display_tiles(x, y, priority,
				window);
	}
	if (window->error_no != 0)
		return (84);
	return (0);
}

int display_map(window_t *window)
{
	if (check_invalid_map_display(window) != 0)
		return (84);
	for (int priority = 0; priority != PRIORITY_MAX + 1; priority++)
		if (display_area(priority, window) != 0)
			return (84);
	return (0);
}
