/*
** EPITECH PROJECT, 2018
** my_cook_2017
** File description:
** my.h
*/

#include "my.h"
#include "rpg.h"

void start_scene_music(scene_t *scene)
{
	if (scene->music) {
		sfMusic_play(scene->music);
		sfMusic_setLoop(scene->music, sfTrue);
	}
}

int process_pre_window(my_w_t *window)
{
	sfRenderWindow_setFramerateLimit(window->window, 60);
	start_scene_music(window->current->value);
	if (add_scene_to_display_list(window->current, window) != 0)
		return (84);
	if (load_my_zone(window) != 0)
		return (84);
	return (0);
}

int main()
{
	my_w_t window = init_my_window();

	if (check_invalid_window_init(window.error_no) != 0)
		return (84);
	if (process_pre_window(&window) != 0)
		return (84);
	while (sfRenderWindow_isOpen(window.window)) {
		get_time(&window);
		sfRenderWindow_clear(window.window, sfBlack);
		if (game_lobby(&window) != 0)
			return (84);
		sfRenderWindow_display(window.window);
	}
	destroy_and_free(&window);
	return (0);
}
