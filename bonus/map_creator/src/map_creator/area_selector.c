/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** area_selector
*/

#include "map_editor.h"

v2i area_selector(void)
{
	v2i area;

	my_printf("Area X : ");
	area.x = my_getnbr(my_get_next_line(0));
	my_putchar('\n');
	my_printf("Area Y : ");
	area.y = my_getnbr(my_get_next_line(0));
	my_putchar('\n');
	return (area);
}