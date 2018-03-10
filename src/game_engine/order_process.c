/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "my.h"

void get_an_order(my_w_t *window)
{
	unsigned int order = rand() % 10;

	if (GAME_T.customers == 4)
		GAME_T.customers = 0;
	GAME_T.order = GAME_T.all_recipes[order];
	add_to_list(GAME_SCENE, (int)GAME_T.order[0], 2, window);
	add_to_list(GAME_SCENE, 35 + GAME_T.customers,
		3, window);
	GAME_T.customers++;
}

void order_process(my_w_t *window)
{
	if (GAME_T.order != NULL && GAME_T.spawn_time <= 0) {
		take_off_recipe_and_png(window);
		SCORE_T.score_points -= 75;
		set_string(SCORE_T.score_points, TEXT.score);
		sfMusic_play(AUDIO_L.fail_sound);
	}
	if (GAME_T.order == NULL) {
		get_an_order(window);
		GAME_T.spawn_time = GAME_T.spawn_time_max;
	} else {
		GAME_T.spawn_time--;
	}
}
