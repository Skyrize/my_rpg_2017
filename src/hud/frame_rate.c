/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "rpg.h"
#include "my.h"

int frame_rate_more(my_w_t *window)
{
	scene_t *option_scene = hm_get_bucket(window->scenes, OPTION_GAME);
	bucket_t *text_bucket = hm_get_bucket(option_scene->texts, "FRAME");

	sfText_setString(text_bucket->value, int_to_str(10));

	window->framerate_game += 10;
	sfRenderWindow_setFramerateLimit(window->window,
	window->framerate_game);
}

int frame_rate_less(my_w_t *window)
{
	scene_t *option_scene = hm_get_bucket(window->scenes, OPTION_GAME);
	bucket_t *text_bucket = hm_get_bucket(option_scene->texts, "FRAME");

	sfText_setString(text_bucket->value, int_to_str(10));
	window->framerate_game -= 10;
	sfRenderWindow_setFramerateLimit(window->window,
	window->framerate_game);
}