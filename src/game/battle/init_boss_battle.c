/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_boss_battle
*/

#include "rpg.h"

int init_boss_enemy(game_t *game)
{
	for (int i = 0; i < 3; i++)
		game->battle.enemy[i] = NULL;
	game->battle.nbr_enemies = 1;
	ENEMY[1] = create_enemy("MAD_OGRE", game);
	if (!ENEMY[1] || !ENEMY[1]->monster || !ENEMY[1]->monster->obj)
		return (84);
	sfRectangleShape_setPosition(ENEMY[1]->monster->obj, V2F(625, 250));
	return (0);
}

int start_boss_battle(game_t *game)
{
	scene_t *battle_scene = hm_get(SCENES, "BATTLE");
	scene_t *game_scene = hm_get(SCENES, "GAME");
	bucket_t *battle = hm_get_bucket(SCENES, "BATTLE_BASIC_BUTTONS");

	if (!game || !battle_scene || !battle || !game)
		return (84);
	if (clean_displayed_scenes_and_add_back(game, "BATTLE") != 0
	|| add_scene_to_display_list(battle, game) != 0)
		return (84);
	CURRENT_BUCKET = hm_get_bucket(SCENES, "BATTLE");
	if (!CURRENT_BUCKET || init_boss_enemy(game) != 0)
		return (84);
	init_character(game);
	if (set_battle(game) != 0 || set_background(game, battle_scene) != 0)
		return (84);
	sfMusic_stop(game_scene->music.music);
	battle_scene->music.music = hm_get(game->libraries.audio,
							"BOSS_BATTLE_MUSIC");
	return (1);
}

int init_boss_battle(char **data, game_t *game)
{
	(void)data;
	if (!game)
		return (84);
	return (start_boss_battle(game));
}