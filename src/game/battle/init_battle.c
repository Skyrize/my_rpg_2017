/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_battle
*/

#include "rpg.h"

int init_battle(window_t *window)
{
	scene_t *battle_scene = hm_get(SCENES, "BATTLE");
	bucket_t *battle_buttons = hm_get_bucket(SCENES,
							"BATTLE_BASIC_BUTTONS");

	clean_displayed_scenes_and_add_back(game, "BATTLE");
	add_scene_to_display_list(battle_buttons, window);
}