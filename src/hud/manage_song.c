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
	scene_t *tmp_value = NULL;

	if (!tmp_scene)
		return (84);
	tmp_value = tmp_scene->value;
	if (tmp_value->play_music == sfFalse)
		tmp_value->play_music = sfTrue;
	else
		tmp_value->play_music = sfFalse;
	return (0);
}