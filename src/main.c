/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** main
*/

#include "my.h"
#include "rpg.h"

void get_time(ctime_t *clocker)
{
	clocker->timer = sfClock_getElapsedTime(clocker->clock);
	clocker->seconds = clocker->timer.microseconds / 1000000.0;
}

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
	return (0);
}

int game_loop(window_t *window, game_t *game)
{
	while (sfRenderWindow_isOpen(window->window)) {
		get_time(&window->clocker);
		sfRenderWindow_clear(window->window, sfBlack);
		if (process_engine(window, game) != 0)
			return (84);
		display_mouse(game, window);
		sfRenderWindow_display(window->window);
	}
	return (0);
}

int main(void)
{
	window_t window;
	game_t game;

	srand(time(NULL));
	if (init(&window, &game) != 0)
		return (84);
	if (start_game(&window, &game) != 0)
		return (84);
	if (game_loop(&window, &game) != 0)
		return (84);
	destroy_and_free(&window, &game);
	return (0);
}
