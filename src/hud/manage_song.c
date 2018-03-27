/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "rpg.h"

int manage_song(my_w_t *window)
{
	bucket_t *tmp_scene = hm_get_bucket(window->scenes, "GAME");
	bucket_t *bucket_scene = hm_get_bucket(window->scenes, OPTION_GAME);
	bucket_t *bucket_texts = NULL;
	scene_t *tmp_value = NULL;
	scene_t *curr_scene = NULL;

	if (!tmp_scene)
		return (84);
	tmp_value = tmp_scene->value;
	curr_scene = bucket_scene->value;
	bucket_texts = hm_get_bucket(curr_scene->texts, "OFFON");
	if (tmp_value->play_music == sfFalse) {
		tmp_value->play_music = sfTrue;
		sfText_setString(bucket_texts->value, "ON");
	} else {
		tmp_value->play_music = sfFalse;
		sfText_setString(bucket_texts->value, "FALSE");
	}
	return (0);
}