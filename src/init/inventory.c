/*
** EPITECH PROJECT, 2017
** my_rpg_2017
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

int init_slot(slot_t *slot, game_t *game)
{
	static char *chut[] = {"SLOT_HELMET", "SLOT_CHEST", "SLOT_PANTS",
	"SLOT_GAUNTLETS", "SLOT_WEAPON", "SLOT_00", "SLOT_01", "SLOT_02",
	"SLOT_03", "SLOT_04", "SLOT_10", "SLOT_11", "SLOT_12", "SLOT_13",
	"SLOT_14", "SLOT_20", "SLOT_21", "SLOT_22", "SLOT_23", "SLOT_24",
	"SLOT_30", "SLOT_31", "SLOT_32", "SLOT_33", "SLOT_34", "SLOT_40",
	"SLOT_41", "SLOT_42", "SLOT_43", "SLOT_44", NULL};
	static int i = 0;
	scene_t *inventory = hm_get(SCENES, "INVENTORY");

	if (!inventory)
		return (84);
	slot->item = NULL;
	slot->slot = hm_get(inventory->objs, chut[i]);
	if (!slot->slot || !slot->slot->obj)
		return (84);
	slot->slot->callback = &click_slot;
	i++;
	return (0);
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
	init_slot(&HELMET, game);
	init_slot(&CHEST, game);
	init_slot(&PANTS, game);
	init_slot(&GAUNTLETS, game);
	init_slot(&WEAPON, game);
	items_foreach(game, NULL, init_slot);
	if (get_starting_items(game) != 0)
		return (84);
	return (0);
}
