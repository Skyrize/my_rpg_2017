/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

my_w_t init_my_window(void)
{
	my_w_t window;

	window.error_no = 0;
	window.displayed_scenes = NULL;
	if (init_my_textures_lib(&window) != 0
	|| init_my_map(&window) != 0) {
		window.error_no = 84;
		return (window);
	}
	return (window);
}
