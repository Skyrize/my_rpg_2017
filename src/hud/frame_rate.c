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
	bucket_t *bucket_scene = hm_get_bucket(window->scenes, OPTION_GAME);
	scene_t *scene_option = NULL;
	bucket_t *text_bucket = NULL;

	if (!bucket_scene)
		return (84);
	scene_option = bucket_scene->value;
	if (!scene_option)
		return (84);
	text_bucket = hm_get_bucket(scene_option->texts, "FRAME");
	if (!text_bucket)
		return (84);
	if ((window->framerate_game += 10) >= 120)
		window->framerate_game = 120;
	sfText_setString(text_bucket->value,
	(char *)int_to_str(window->framerate_game));
	sfRenderWindow_setFramerateLimit(window->window,
	window->framerate_game);
	return (0);
}

int frame_rate_less(my_w_t *window)
{
	bucket_t *bucket_scene = hm_get_bucket(window->scenes, OPTION_GAME);
	scene_t *scene_option = NULL;
	bucket_t *text_bucket = NULL;

	if (!bucket_scene)
		return (84);
	scene_option = bucket_scene->value;
	if (!scene_option)
		return (84);
	text_bucket = hm_get_bucket(scene_option->texts, "FRAME");
	if (!text_bucket)
		return (84);
	if ((window->framerate_game -= 10) <= 30)
		window->framerate_game = 30;
	sfText_setString(text_bucket->value,
	(char *)int_to_str(window->framerate_game));
	sfRenderWindow_setFramerateLimit(window->window,
	window->framerate_game);
	return (0);
}