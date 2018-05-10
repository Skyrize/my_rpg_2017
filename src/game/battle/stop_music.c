/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** stop_music
*/

#include "rpg.h"

void stop_battle_music(game_t *game)
{
	scene_t *scene = hm_get(SCENES, "BATTLE");

	if (!scene)
		return;
	sfMusic_stop(scene->music.music);
}