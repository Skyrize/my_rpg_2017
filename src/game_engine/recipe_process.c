/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "my.h"

void reset_to_zero(my_w_t *window)
{
	sfText_setString(TEXT.apple, "0");
	sfText_setString(TEXT.banana, "0");
	sfText_setString(TEXT.blue_fish, "0");
	sfText_setString(TEXT.bread, "0");
	sfText_setString(TEXT.carrot, "0");
	sfText_setString(TEXT.cheese, "0");
	sfText_setString(TEXT.garlic, "0");
	sfText_setString(TEXT.orange, "0");
	sfText_setString(TEXT.pastecos, "0");
	sfText_setString(TEXT.pumkin, "0");
	sfText_setString(TEXT.raw_meat, "0");
	sfText_setString(TEXT.red_fish, "0");

}

void take_off_recipe_and_png(my_w_t *window)
{
	remove_from_list(window, GAME_T.order[0], 2);
	remove_from_list(window, 34 + GAME_T.customers, 3);
	GAME_T.order = NULL;
	reset_to_zero(window);
	init_recipe(window);
}

int check_recipe_done(my_w_t *window)
{
	if (!GAME_T.order)
		return (0);
	if (my_arraycmp(GAME_T.order, GAME_T.recipe) != 0) {
		sfMusic_play(AUDIO_L.bonk_sound);
		reset_to_zero(window);
		init_recipe(window);
		return (0);
	}
	sfMusic_play(AUDIO_L.ting_sound);
	take_off_recipe_and_png(window);
	SCORE_T.score_points += 100;
	set_string(SCORE_T.score_points, TEXT.score);
	return (0);
}
