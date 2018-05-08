/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** add.c
*/

#include "rpg.h"

int add_new_to_slot(char *name, sfVector2f *pos, slot_t *slot, game_t *game)
{
	item_t *item = create_item(name, game);

	if (!item)
		return (84);
	slot->item = item;
	sfRectangleShape_setPosition(item->obj->obj, *pos);
	return (0);
}