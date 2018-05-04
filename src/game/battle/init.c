/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_battle
*/

#include "rpg.h"

int init_enemies(game_t *game)
{
	int nbr = rand() % 2 + 1;

	game->battle.nbr_enemies = nbr;
	for (int i = 0; i < 3; i++)
		game->battle.enemy[i] = NULL;
	game->battle.enemy[0] = create_enemy("SKELETON", game);
	if (!game->battle.enemy[0])
		return (84);
	sfRectangleShape_setPosition(game->battle.enemy[0]->\
	monster->obj, V2F(600, 200));
	if (nbr == 1)
		return (0);
	game->battle.enemy[2] = create_enemy("SKELETON", game);
	if (!game->battle.enemy[2])
		return (84);
	sfRectangleShape_setPosition(game->battle.enemy[2]->\
	monster->obj, V2F(650, 300));
	return (0);
}

void init_character(game_t *game)
{
	sfRectangleShape_setTextureRect(PLAYER_CHARACTER->obj,
	(sfIntRect){50, 200, 50, 100});
	sfRectangleShape_setPosition(PLAYER_CHARACTER->obj, V2F(100, 225));
}

int init_battle(game_t *game)
{
	scene_t *battle_scene = hm_get(SCENES, "BATTLE");
	bucket_t *battle = hm_get_bucket(SCENES, "BATTLE_BASIC_BUTTONS");

	if (!game || !battle_scene || !battle)
		return (84);
	clean_displayed_scenes_and_add_back(game, "BATTLE");
	add_scene_to_display_list(battle, game);
	CURRENT_BUCKET = hm_get_bucket(SCENES, "BATTLE");
	if (!CURRENT_BUCKET || init_enemies(game) != 0)
		return (84);
	init_character(game);
	update_element_in_battle(game);
	game->battle.special_hit = 0;
	game->battle.last_enemy_turn = 0;
	game->battle.lose = 0;
	game->battle.win = 0;
	ENEMY_TURN = 0;
	PLAYER_TURN = 1;
	return (0);
}