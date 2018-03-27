/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int key_french(my_w_t *window)
{
	bucket_t *bucket_scene = hm_get_bucket(window->scenes, CONTROL_KEY);
	bucket_t *bucket_texts = NULL;
	scene_t *curr_scene = NULL;

	if (!bucket_scene)
		return (84);
	curr_scene = bucket_scene->value;
	bucket_texts = hm_get_bucket(curr_scene->texts, "USER_KEY");
	sfText_setString(bucket_texts->value, "FRENCH KEYBOARD");
	return (0);
}

int key_english(my_w_t *window)
{
	bucket_t *bucket_scene = hm_get_bucket(window->scenes, CONTROL_KEY);
	bucket_t *bucket_texts = NULL;
	scene_t *curr_scene = NULL;

	if (!bucket_scene)
		return (84);
	curr_scene = bucket_scene->value;
	bucket_texts = hm_get_bucket(curr_scene->texts, "USER_KEY");
	sfText_setString(bucket_texts->value, "ENGLISH KEYBOARD");
	return (0);
}