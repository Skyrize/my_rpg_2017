/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** utils
*/

#include "rpg.h"

char *get_item_rarity(char *item)
{
	if (item[0] == 'C')
		return ("COMMON");
	else if (item[0] == 'R')
		return ("RARE");
	else if (item[0] == 'E')
		return ("EPIC");
	return ("MYTHIC");
}

char *get_item_type(char *item)
{
	int i = 0;

	while (item[i++] != '_');
	i++;
	if (!my_strncmp(item + i, "CHEST", 5))
		return ("CHEST");
	if (!my_strncmp(item + i, "HELMET", 6))
		return ("HELMET");
	if (!my_strncmp(item + i, "GAUNTLETS", 9))
		return ("GAUNTLETS");
	if (!my_strncmp(item + i, "PANTS", 5))
		return ("PANTS");
	if (!my_strncmp(item + i, "BOW", 3))
		return ("BOW");
	if (!my_strncmp(item + i, "WAND", 4))
		return ("WAND");
	return ("SWORD");
}