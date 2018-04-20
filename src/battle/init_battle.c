/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_battle
*/

#include "rpg.h"

int init_battle(my_w_t *window)
{
	scene_t *battle_scene = hm_get(window->scenes, "BATTLE");
	bucket_t *battle_buttons = hm_get_bucket(window->scenes,
							"BATTLE_BASIC_BUTTONS");

	clean_displayed_scenes_and_add_back(window, "BATTLE");
	add_scene_to_display_list(battle_buttons, window);
}