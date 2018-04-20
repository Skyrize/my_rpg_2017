/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "rpg.h"
#include "my.h"

int frame_rate_more(window_t *window)
{
	bucket_t *bucket_scene = hm_get_bucket(SCENES, OPTION_GAME);
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
	if ((FRAMERATE += 10) >= 120)
		FRAMERATE = 120;
	sfText_setString(text_bucket->value,
	(char *)int_to_str(FRAMERATE));
	sfRenderWindow_setFramerateLimit(window->window,
	FRAMERATE);
	return (0);
}

int frame_rate_less(window_t *window)
{
	bucket_t *bucket_scene = hm_get_bucket(SCENES, OPTION_GAME);
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
	if ((FRAMERATE -= 10) <= 30)
		FRAMERATE = 30;
	sfText_setString(text_bucket->value,
	(char *)int_to_str(FRAMERATE));
	sfRenderWindow_setFramerateLimit(window->window,
	FRAMERATE);
	return (0);
}