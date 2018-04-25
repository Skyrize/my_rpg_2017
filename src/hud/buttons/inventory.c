/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"



int add_to_slot(slot_t *slot, sfVector2i *pos, game_t *game)
{
	static sfVector2f slot_pos = {563, 290};

	if (!slot->item->obj || !slot->item->obj->obj) {
		my_printf("NULL\n");
		return (84);
	}
	if (ITEMS[pos->y][pos->x].item->obj) {
		my_printf("ALREADY SOMETHING\n");
		return (1);
	}
	ITEMS[pos->y][pos->x] = *slot;
	sfRectangleShape_setPosition(slot->item->obj->obj,
	V2F(slot_pos.x * (pos->x + 1), slot_pos.y * (pos->y + 1)));
	return (0);
}

int add_helmet(slot_t *slot, game_t *game)
{
	static sfVector2f slot_pos = {634, 84};

	if (!slot->item->obj || !slot->item->obj->obj) {
		my_printf("NULL\n");
		return (84);
	}
	if (HELMET.item->obj) {
		my_printf("ALREADY SOMETHING\n");
		return (1);
	}
	HELMET = *slot;
	sfRectangleShape_setPosition(slot->item->obj->obj, slot_pos);
	return (0);
}
int add_chest(slot_t *slot, game_t *game)
{
	static sfVector2f slot_pos = {634, 129};

	if (!slot->item->obj || !slot->item->obj->obj) {
		my_printf("NULL\n");
		return (84);
	}
	if (CHEST.item->obj) {
		my_printf("ALREADY SOMETHING\n");
		return (1);
	}
	CHEST = *slot;
	sfRectangleShape_setPosition(slot->item->obj->obj, slot_pos);
	return (0);
}
int add_pants(slot_t *slot, game_t *game)
{
	static sfVector2f slot_pos = {634, 172};

	if (!slot->item->obj || !slot->item->obj->obj) {
		my_printf("NULL\n");
		return (84);
	}
	if (PANTS.item->obj) {
		my_printf("ALREADY SOMETHING\n");
		return (1);
	}
	PANTS = *slot;
	sfRectangleShape_setPosition(slot->item->obj->obj, slot_pos);
	return (0);
}
int add_gauntlets(slot_t *slot, game_t *game)
{
	static sfVector2f slot_pos = {589, 128};

	if (!slot->item->obj || !slot->item->obj->obj) {
		my_printf("NULL\n");
		return (84);
	}
	if (GAUNTLETS.item->obj) {
		my_printf("ALREADY SOMETHING\n");
		return (1);
	}
	GAUNTLETS = *slot;
	sfRectangleShape_setPosition(slot->item->obj->obj, slot_pos);
	return (0);
}
int add_weapon(slot_t *slot, game_t *game)
{
	static sfVector2f slot_pos = {678, 128};

	if (!slot->item->obj || !slot->item->obj->obj) {
		my_printf("NULL\n");
		return (84);
	}
	if (WEAPON.item->obj) {
		my_printf("ALREADY SOMETHING\n");
		return (1);
	}
	WEAPON = *slot;
	sfRectangleShape_setPosition(slot->item->obj->obj, slot_pos);
	return (0);
}





int helmet_slot(window_t *window, game_t *game)
{
	(void)game;
	///rajouter les checks
	(void)window;
	my_printf("Helmet slot in construction.\n");
	return (0);
}

int chest_slot(window_t *window, game_t *game)
{
	(void)game;
	(void)window;
	my_printf("Chest slot in construction.\n");
	return (0);
}

int gauntlets_slot(window_t *window, game_t *game)
{
	(void)game;
	(void)window;
	my_printf("Gauntlets slot in construction.\n");
	return (0);
}

int pants_slot(window_t *window, game_t *game)
{
	(void)game;
	(void)window;
	my_printf("Pants slot in construction.\n");
	return (0);
}

int weapon_slot(window_t *window, game_t *game)
{
	(void)game;
	(void)window;
	my_printf("Weapon slot in construction.\n");
	return (0);
}

int slot(window_t *window, game_t *game)
{
	(void)game;
	(void)window;
	my_printf("Inventory slot in construction.\n");
	return (0);
}

int inventory(window_t *window, game_t *game)
{
	(void)window;
	return (button_display_hide_scene(INVENTORY_GAME,
		NULL, game));
}
