/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** select_enemy
*/

#include "rpg.h"

int attack(window_t *window, game_t *game)
{
	(void)window;
	add_scene_to_display_list(hm_get_bucket(SCENES, "ATTACK"), game);
	game->battle.selected_enemy = first_enemy_available(game);
	change_arrow_position(game);
	clean_displayed_scene_name(game, "BATTLE_BASIC_BUTTONS");
	return (0);
}