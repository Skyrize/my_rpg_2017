/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int select_slot(slot_t *slot, game_t *game)
{
	if (!slot->item)
		return (0);
	ITEM_SELECTED = slot->item;
	if (replace_mouse_skin(slot->item->obj, &V2F(16, 16), game) != 0)
		return (84);
	slot->item = NULL;
	return (0);
}

int drop_slot(slot_t *slot, game_t *game)
{
	item_t *tmp;

	if (!slot->item) {
		slot->item = ITEM_SELECTED;
		sfRectangleShape_setPosition(slot->item->obj->obj, slot->pos);
		ITEM_SELECTED = NULL;
		return (reset_mouse_skin(game));
	} else {
		tmp = slot->item;
		slot->item = ITEM_SELECTED;
		sfRectangleShape_setPosition(slot->item->obj->obj, slot->pos);
		ITEM_SELECTED = NULL;
		ITEM_SELECTED = tmp;
		return (replace_mouse_skin(ITEM_SELECTED->obj,
		&V2F(16, 16), game));
	}
	return (0);
}

int click_slot(slot_t *slot, game_t *game)
{
	if (!slot || !game)
		return (84);
	if (!ITEM_SELECTED) {
		return (select_slot(slot, game));
	} else {
		return (drop_slot(slot, game));
	}
	return (0);
}
