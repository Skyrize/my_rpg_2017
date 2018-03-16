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

int check_invalid_animated(sfBool animated)
{
	if (animated != sfTrue && animated != sfFalse) {
		my_printf("WARNING: ANIMATED VALUE CAN ONLY BE '0' ");
		my_printf("FOR FALSE OR '1' FOR TRUE !\n");
		return (84);
	}
	return (0);
}
