/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "../../include/my.h"

void display_char_2d(char *option, char **str)
{
	for (unsigned int i = 0; str[i]; i++) {
		my_printf("%s%s", option, str[i]);
	}
}
