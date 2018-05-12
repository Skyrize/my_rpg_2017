/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** quest_2
*/

#include "rpg.h"

int quest_2(game_t *game)
{
	npc_t *leenas = hm_get(NPCS_LIB, "Lee'nas");

	if (!leenas)
		return (84);
	if (!my_strcmp(leenas->line_01, "I hate ogres! I want to kill them all."))
		return (0);
	make_sound("NEW_QUEST", game);
	leenas->line_01 = my_strdup("I hate ogres! I want to kill them all.");
	leenas->line_02 = my_strdup(" ");
	leenas->line_03 = my_strdup(" ");
	add_xp_to_player(game, 200);
	return (0);
}