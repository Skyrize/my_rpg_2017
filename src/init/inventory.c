/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

void init_selector(item_getter_t *selector)
{
	selector->base_emplacement.x = 0;
	selector->base_emplacement.y = 0;
	selector->base = NULL;
	selector->dest = NULL;
}

void init_slot(slot_t *slot, game_t *game)
{
	slot->item = NULL;
	slot->slot = NULL;
	(void)game;
}

int get_starting_items(game_t *game)
{
	HELMET.item = copy_item_lib("COMMON_HELMET_00", ITEMS_LIB);
	CHEST.item = copy_item_lib("COMMON_CHEST_00", ITEMS_LIB);
	PANTS.item = copy_item_lib("COMMON_PANTS_00", ITEMS_LIB);
	GAUNTLETS.item = copy_item_lib("COMMON_GAUNTLETS_00", ITEMS_LIB);
	WEAPON.item = copy_item_lib("COMMON_BOW_00", ITEMS_LIB);
	my_printf("NOTE: relace weapon init with null and init it when selecting player.\n");
	if (!HELMET.item || !CHEST.item
	|| !PANTS.item || !GAUNTLETS.item || !WEAPON.item) {
		my_printf("WARNING: ERROR IN STARTING ITEMS INITALISATION !\n");
		return (84);
	}
	return (0);
}

int init_inventory(game_t *game)
{
	GOLDS = 100;
	init_selector(&INVENTORY.selector);
	init_slot(&WEAPON, NULL);
	init_slot(&HELMET, NULL);
	init_slot(&CHEST, NULL);
	init_slot(&GAUNTLETS, NULL);
	init_slot(&PANTS, NULL);
	items_foreach(game, NULL, (int (*)())init_slot);
	if (get_starting_items(game) != 0)
		return (84);
	return (0);
}
