/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "../../include/my.h"

void free_char_2d(char **tab)
{
	for (int i = 0; tab[i]; i++)
		free(tab[i]);
	free(tab);
}
