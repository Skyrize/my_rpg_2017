/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_battle
*/

#include "rpg.h"

void init_enemies(game_t *game)
{
	int nbr = rand() % 2 + 1;
	int x = 400;
	int y = 100;

	for (int i = 0; i < 3; i++)
		game->enemy[0].rec = NULL;
	for (int i = 0; i < nbr; i++) {
		game->enemy[i].health = 100 * PLAYER_LEVEL;
		game->enemy[i].armor = 20 * PLAYER_LEVEL;
		game->enemy[i].damages = 20 * PLAYER_LEVEL;
		game->enemy[i].rec = sfRectangleShape_create();
		sfRectangleShape_setTexture(game->enemy[i].rec,
		hm_get(game->libraries.textures, "SKELETON_01"), sfTrue);
		sfRectangleShape_setTextureRect(game->enemy[i].rec,
		(sfIntRect){0, 100, 50, 100});
		sfRectangleShape_setPosition(game->enemy[i].rec, V2F(x, y));
		x += 100;
		y += 100;
	}
}

void init_character(game_t *game)
{
	sfRectangleShape_setTextureRect(PLAYER_CHARACTER->obj,
	(sfIntRect){0, 100, 50, 100});
	sfRectangleShape_setPosition(PLAYER_CHARACTER->obj, V2F(100, 200));
}

int init_battle(game_t *game)
{
	scene_t *battle_scene = hm_get(SCENES, "BATTLE");
	bucket_t *battle_buttons = hm_get_bucket(SCENES,
							"BATTLE_BASIC_BUTTONS");

	if (!game || !battle_scene || !battle_buttons)
		return (84);
	clean_displayed_scenes_and_add_back(game, "BATTLE");
	add_scene_to_display_list(battle_buttons, game);
	CURRENT_SCENE = hm_get_bucket(SCENES, "BATTLE");
	init_enemies(game);
	init_character(game);
	return (0);
}