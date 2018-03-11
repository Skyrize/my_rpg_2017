/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_invalid_key_word(char *last_word_used, char *key_word)
{
	if (last_word_used == NULL) {
		my_printf("WARNING: '%s' ISN'T A VALID KEYWORD !\n", key_word);
		return (84);
	}
	return (0);
}
