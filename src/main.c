/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** main
*/

#include "my.h"
#include "rpg.h"

int init(window_t *window, game_t *game)
{
	if (init_window(window) != 0) {
		my_printf("WARNING: ERROR IN WINDOW INITIALISATION !\n");
		return (84);
	}
	if (init_game(game) != 0) {
		my_printf("WARNING: ERROR IN GAME INITIALISATION !\n");
		return (84);
	}
	my_printf("WARNING: 5 param in display_tiles\n");
	return (0);
}

int game_loop(window_t *window, game_t *game)
{
	while (sfRenderWindow_isOpen(window->window)) {
		get_time(&window->clocker);
		sfRenderWindow_clear(window->window, sfBlack);
		if (game_lobby(window, game) != 0)
			return (84);
		sfRenderWindow_display(window->window);
	}
	return (0);
}

int main()
{
	window_t window;
	game_t game;

	if (init(&window, &game) != 0)
		return (84);
	if (start_game(&window, &game) != 0)
		return (84);
	if (game_loop(&window, &game) != 0)
		return (84);
	destroy_and_free(&window, &game);
	return (0);
}
