/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int click_item(sfVector2i *tab_pos, item_t *item, game_t *game)
{
	if (!item || !game)
		return (84);
	my_printf("tabpos = %d / %d", tab_pos->x, tab_pos->y);
	return (1);
}

int click_slot(sfVector2i *tab_pos, item_t *item, game_t *game)
{
	if (!item || !game)
		return (84);
	my_printf("tabpos = %d / %d", tab_pos->x, tab_pos->y);
	return (1);
}