/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** main
*/

#include "my.h"
#include "rpg.h"

int init_rectangle_divers(game_t *game)
{
	scene_t *battle_game = NULL;
	obj_t *obj = NULL;

	if (!game)
		return (84);
	battle_game = hm_get(game->scenes, "BATTLE");
	if (!battle_game)
		return (84);
	obj = hm_get(battle_game->objs, "VERSUS_ICO");
	if (!obj)
		return (84);
	sfRectangleShape *versus_ico = obj->obj;
	sfRectangleShape_setFillColor(versus_ico,
	(sfColor){255, 255, 255 , 0});
	return (0);
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
	if (init_rectangle_divers(game) != 0) {
		my_printf("WARNING: ERROR IN REC DIVERS INITIALISATION !\n");
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
