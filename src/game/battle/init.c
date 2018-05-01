/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_battle
*/

#include "rpg.h"

void set_enemy_alone(game_t *game, texture_t *texture, int i)
{
	game->battle.enemy[i].health = 100 * PLAYER_LEVEL;
	game->battle.enemy[i].armor = 20 * PLAYER_LEVEL;
	game->battle.enemy[i].damages = 20 * PLAYER_LEVEL;
	game->battle.enemy[i].rec = sfRectangleShape_create();
	sfRectangleShape_setTexture(game->battle.enemy[i].rec,
	texture->texture, sfTrue);
	sfRectangleShape_setTextureRect(game->battle.enemy[i].rec,
	(sfIntRect){0, 100, 50, 100});
	sfRectangleShape_setPosition(game->battle.enemy[i].rec,
	V2F(600 + (25 * i), 200 + (50 * i)));
	sfRectangleShape_setSize(game->battle.enemy[i].rec, V2F(50, 100));
}

void init_enemies(game_t *game)
{
	int nbr = rand() % 2 + 1;
	texture_t *texture = hm_get(TEXTURES_LIB, "SKELETON_01");

	for (int i = 0; i < 3; i++)
		game->battle.enemy[i].rec = NULL;
	set_enemy_alone(game, texture, 0);
	if (nbr == 2)
		set_enemy_alone(game, texture, 2);
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

	if (!game || !battle_scene)
		return (84);
	clean_displayed_scenes_and_add_back(game, "BATTLE");
	CURRENT_BUCKET = hm_get_bucket(SCENES, "BATTLE");
	init_enemies(game);
	init_character(game);
	update_element_in_battle(game);
	game->battle.special_hit = 0;
	game->battle.last_enemy_turn = 0;
	ENEMY_TURN = 0;
	PLAYER_TURN = 1;
	return (0);
}