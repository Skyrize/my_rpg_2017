/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

void replace_key(int choice, my_w_t *window)
{
	if (choice == 0) {
		window->key_player->up = (sfKeyCode *)sfKeyZ;
		window->key_player->down = (sfKeyCode *)sfKeyS;
		window->key_player->left = (sfKeyCode *)sfKeyQ;
		window->key_player->right = (sfKeyCode *)sfKeyD;
		window->key_player->up_1 = (sfKeyCode *)sfKeyUp;
	} else {
		window->key_player->up = (sfKeyCode *)sfKeyW;
		window->key_player->down = (sfKeyCode *)sfKeyS;
		window->key_player->left = (sfKeyCode *)sfKeyA;
		window->key_player->right = (sfKeyCode *)sfKeyD;
		window->key_player->up_1 = (sfKeyCode *)sfKeyUp;
	}
}

int key_french(my_w_t *window)
{
	bucket_t *bucket_scene = hm_get_bucket(window->scenes, CONTROL_KEY);
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

int key_english(my_w_t *window)
{
	bucket_t *bucket_scene = hm_get_bucket(window->scenes, CONTROL_KEY);
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