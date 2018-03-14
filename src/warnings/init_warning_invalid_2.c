/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_invalid_window_init(int error_no)
{
	if (error_no != 0) {
		my_printf("WARNING: ERROR IN INITIALISATION\n");
		return (84);
	}
	return (0);
}
