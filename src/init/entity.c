/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** entity.c
*/

#include "rpg.h"

int init_monsters_lib(game_t *game)
{
	const key_word_t monster_keys[] = {
	{"MONSTERS", 0, &get_monster, NULL},
	{"TEXTURE", 0, &get_enemy_data_texture, NULL},
	{"ZONE", 0, &get_monster_zone, NULL},
	{"STATS", 3, &get_monster_stats, (char *[]) {"HEALTH", "ARMOR",
	"DAMAGES", NULL}},
	{NULL, 0, NULL, NULL}};
	get_infos_t infos = {"pcf/monster.pcf", INIT_CHAR, monster_keys,
	&list_savior};

	MONSTERS_LIB = hm_create(64, &sfMusic_destroy);
	if (!MONSTERS_LIB || analyse_pcf(game, &infos) != 0) {
		my_printf("WARNING: ERROR IN MONSTERS LIB INIT !\n");
		return (84);
	}
	return (0);
}