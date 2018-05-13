/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** clean_battle_scenes
*/

#include "rpg.h"

int stop_battle_music(game_t *game)
{
	scene_t *scene = hm_get(SCENES, "BATTLE");

	if (!scene)
		return (84);
	sfMusic_stop(scene->music.music);
	return (0);
}

void lose_tp(game_t *game)
{
	unload_my_zone(game);
	ZONE_COOR_X = 0;
	ZONE_COOR_Y = 0;
	AREA_COOR_X = 0;
	AREA_COOR_Y = 0;
	TILE_COOR_X = 7;
	TILE_COOR_Y = 4;
	load_my_zone(game);
}

void clean_battle_scenes(game_t *game)
{
	clean_displayed_scenes_and_add_back(game, "GAME");
	add_scene_to_display_list(hm_get_bucket(SCENES, "WIN_SCREEN"), game);
	add_scene_to_display_list(hm_get_bucket(SCENES, "HEALTH_HUD"), game);
	add_scene_to_display_list(hm_get_bucket(SCENES, "AREA_HUD"), game);
	CURRENT_BUCKET = hm_get_bucket(SCENES, "WIN_SCREEN");
	stop_battle_music(game);
	sfRectangleShape_setPosition(PLAYER_CHARACTER->obj, PLAYER_POS);
}