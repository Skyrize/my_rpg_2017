/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

void replace_key(int choice, window_t *window)
{
	if (choice == 0) {
		KEY_PLAYER->up = (sfKeyCode *)sfKeyZ;
		KEY_PLAYER->down = (sfKeyCode *)sfKeyS;
		KEY_PLAYER->left = (sfKeyCode *)sfKeyQ;
		KEY_PLAYER->right = (sfKeyCode *)sfKeyD;
		KEY_PLAYER->up_1 = (sfKeyCode *)sfKeyUp;
	} else {
		KEY_PLAYER->up = (sfKeyCode *)sfKeyW;
		KEY_PLAYER->down = (sfKeyCode *)sfKeyS;
		KEY_PLAYER->left = (sfKeyCode *)sfKeyA;
		KEY_PLAYER->right = (sfKeyCode *)sfKeyD;
		KEY_PLAYER->up_1 = (sfKeyCode *)sfKeyUp;
	}
}

int key_french(window_t *window)
{
	bucket_t *bucket_scene = hm_get_bucket(SCENES, CONTROL_KEY);
	bucket_t *bucket_texts = NULL;
	scene_t *curr_scene = NULL;

	if (!bucket_scene)
		return (84);
	curr_scene = bucket_scene->value;
	bucket_texts = hm_get_bucket(curr_scene->texts, "USER_KEY");
	sfText_setString(bucket_texts->value, "FRENCH");
	replace_key(0, window);
	return (0);
}

int key_english(window_t *window)
{
	bucket_t *bucket_scene = hm_get_bucket(SCENES, CONTROL_KEY);
	bucket_t *bucket_texts = NULL;
	scene_t *curr_scene = NULL;

	if (!bucket_scene)
		return (84);
	curr_scene = bucket_scene->value;
	bucket_texts = hm_get_bucket(curr_scene->texts, "USER_KEY");
	sfText_setString(bucket_texts->value, "ENGLISH");
	replace_key(1, window);
	return (0);
}