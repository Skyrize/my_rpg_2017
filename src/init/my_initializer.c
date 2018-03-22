/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

ctime_t init_timer(void)
{
	ctime_t clocker;

	clocker.clock = sfClock_create();
	clocker.seconds = 0;
	return (clocker);
}

int init_game_tools(my_w_t *window)
{
	(void)window;
	return (0);
}

void init_window_values(my_w_t *window)
{
	window->error_no = 0;
	window->clocker = init_timer();
	MOUSE_POS = (sfVector2i){0, 0};
	window->window = sfRenderWindow_create((sfVideoMode){WINDOW_WIDTH,
		WINDOW_HEIGHT, WINDOW_BITS_PER_PIXEL},
	GAME_TITLE, sfClose, NULL);
	window->displayed_scenes = NULL;
}

my_w_t init_my_window(void)
{
	my_w_t window;

	init_window_values(&window);
	if (!window.window || init_my_textures_lib(&window) != 0
	|| init_my_audio_lib(&window) != 0 || init_my_fonts_lib(&window) != 0
	|| init_my_scenes(&window) != 0 || init_my_map(&window) != 0
	|| !window.clocker.clock || init_game_tools(&window) != 0
	|| init_my_buttons(&window) != 0 || init_my_player(&window) != 0) {
		window.error_no = 84;
		return (window);
	}
	window.current = hm_get_bucket(window.scenes, STARTING_SCENE_NAME);
	if (check_scene_not_created(window.current,
		"my_initializer.c", 42, STARTING_SCENE_NAME) != 0)
		window.error_no = 84;
	return (window);
}
