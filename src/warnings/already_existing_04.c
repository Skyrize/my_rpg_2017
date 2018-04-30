/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_already_existing_monster(hashmap_t *hashmap, char *monster_name)
{
	enemy_data_t *monster = hm_get(hashmap, monster_name);

	if (monster != NULL) {
		my_printf("WARNING: MONSTER '%s' REDECLARED IN MONSTER.PCF !\n",
		monster_name);
		return (84);
	}
	return (0);
}
