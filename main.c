/*
** EPITECH PROJECT, 2018
** my_cook_2017
** File description:
** my.h
*/

#include "my.h"
#include "rpg.h"

void process_pre_window(my_w_t *window)
{
	sfRenderWindow_setFramerateLimit(window->window, 60);
	//sfMusic_play(AUDIO_L.game_music);
	//sfMusic_setLoop(AUDIO_L.game_music, sfTrue);
}

int main(/*int ac, char **av, char **env*/)
{
	my_w_t window = init_my_window();

	if (window.error_no != 0)
		return (84);
	process_pre_window(&window);
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
