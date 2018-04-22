/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int init_inventory(game_t *game)
{/* 
	slot_t sweap;
	slot_t shel;
	slot_t schest;
	slot_t sgaunt;
	slot_t spants;
	slot_t item;
	item_t weap;
	item_t hel;
	item_t chest;
	item_t gaunt;
	item_t pants;
	sweap.slot = create_obj(&(obj_data_t){"ITEM", "COMMON_BOW_00", 1, V2F(585, 135)}, window);
	shel.slot = create_obj(&(obj_data_t){"ITEM", "COMMON_HELMET_00", 1, V2F(635, 85)}, window);
	schest.slot = create_obj(&(obj_data_t){"ITEM", "COMMON_CHEST_00", 1, V2F(635, 135)}, window);
	sgaunt.slot = create_obj(&(obj_data_t){"ITEM", "COMMON_GAUNTLETS_00", 1, V2F(690, 135)}, window);
	spants.slot = create_obj(&(obj_data_t){"ITEM", "COMMON_PANTS_00", 1, V2F(635, 185)}, window);
	obj_t *w = create_obj(&(obj_data_t){"ITEM", "COMMON_BOW_00", 1, V2F(585, 135)}, window);
	obj_t *h = create_obj(&(obj_data_t){"ITEM", "COMMON_HELMET_00", 1, V2F(635, 85)}, window);
	obj_t *c = create_obj(&(obj_data_t){"ITEM", "COMMON_CHEST_00", 1, V2F(635, 135)}, window);
	obj_t *g = create_obj(&(obj_data_t){"ITEM", "COMMON_GAUNTLETS_00", 1, V2F(690, 135)}, window);
	obj_t *p = create_obj(&(obj_data_t){"ITEM", "COMMON_PANTS_00", 1, V2F(635, 185)}, window);
	ITEM_SELECTOR.base = NULL;
	ITEM_SELECTOR.dest = NULL;
	HELMET.item.obj = NULL;
	CHEST.item.obj = NULL;
	GAUNTLETS.item.obj = NULL;
	PANTS.item.obj = NULL;
	WEAPON.item.obj = NULL;
	///to change
	GOLDS = 100;
	for (int x = 0; x != INVENTORY_SIZE_X; x++)
		for (int y = 0; y != INVENTORY_SIZE_Y; y++) {
			ITEMS[y][x].item.obj = NULL;
		}
	item.item.obj = create_obj(&(obj_data_t){"ITEM", "MYTHIC_CHEST_01", 1, V2F(635, 185)}, window);
	weap.stats = (item_stat_t){100, 10, 10};
	hel.stats = (item_stat_t){100, 10, 10};
	chest.stats = (item_stat_t){100, 10, 10};
	gaunt.stats = (item_stat_t){100, 10, 10};
	pants.stats = (item_stat_t){100, 10, 10};
	weap.obj = w;
	hel.obj = h;
	chest.obj = c;
	gaunt.obj = g;
	pants.obj = p;
	sweap.item = weap;
	shel.item = hel;
	schest.item = chest;
	sgaunt.item = gaunt;
	spants.item = pants;
	add_helmet(&shel, window);
	add_chest(&schest, window);
	add_pants(&spants, window);
	add_weapon(&sweap, window);
	add_gauntlets(&sgaunt, window);
	add_to_slot(&item, &V2I(0, 0), window); */
	(void)game;
	return (0);
}
