/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_undefined_item(bucket_t *item, char *data)
{
	if (!item) {
		my_printf("WARNING: YOU ASKED FOR '%s' ", data);
		my_printf("DATA BUT ITEM ISN'T DEFINED !\n");
		return (84);
	}
	return (0);
}
