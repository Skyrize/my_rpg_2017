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

my_w_t init_my_window(void)
{
	my_w_t window;

	window.error_no = 0;
	window.clocker = init_timer();
	window.window = sfRenderWindow_create((sfVideoMode){1600, 900, 32},
	"World of CookCraft", sfResize | sfClose, NULL);
	if (!window.window || init_my_textures_lib(&window) != 0
	|| init_my_audio_lib(&window) != 0 || init_my_fonts_lib(&window) != 0
	|| init_my_scenes(&window) != 0
	|| !window.clocker.clock || init_game_tools(&window) != 0)
		window.error_no = 84;
	window.actual_scene = "START";
	return (window);
}
