/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_invalid_index(int index)
{
	if (index < 0 || index >= OBJS_TYPE_NB) {
		my_printf("WARNING: INDEX HAS TO STICK BETWEEN 0 AND %d !\n",
		OBJS_TYPE_NB);
		return (84);
	}
	return (0);
}

int check_invalid_key_word(char *last_word_used, char **type, char **infos,
	int error_no)
{
	if (error_no != 0)
		return (84);
	if (last_word_used == NULL) {
		my_printf("WARNING: '%s' ISN'T A VALID KEYWORD !\n",
		type[0]);
		return (84);
	}
	free_char_2d(type);
	free_char_2d(infos);
	return (0);
}

int check_invalid_file(int fd, char *filename)
{
	if (fd == -1) {
		my_printf("WARNING: CAN'T FIND '%s' FILE !\n", filename);
		return (84);
	}
	return (0);
}
