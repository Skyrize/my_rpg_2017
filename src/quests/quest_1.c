/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** quest_1
*/

#include "rpg.h"

int quest_1(game_t *game)
{
	npc_t *npc = hm_get(NPCS_LIB, "Caleof");

	if (!npc)
		return (84);
	if (!my_strcmp(npc->line_01, "You may have to look for information,"))
		return (0);
	make_sound("NEW_QUEST", game);
	npc->line_01 = my_strdup("You may have to look for information,");
	npc->line_02 = my_strdup( \
			" you should start with the tavern. Please hurry!");
	npc->line_03 = my_strdup(" ");
	return (0);
}

int quests(char **action, game_t *game)
{
	int nbr = 0;

	if (!action || !game)
		return (84);
	nbr = my_getnbr(action[1]);
	if (nbr == 1)
		quest_1(game);
	else if (nbr == 2)
		quest_2(game);
	return (0);
}