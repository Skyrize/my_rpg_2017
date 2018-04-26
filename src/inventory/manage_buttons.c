/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int process_inventory_button_over(sfVector2i *pos, obj_t *button, game_t *game)
{
	if (button_fly_over(button, MOUSE_POS) == 1 &&
	buttonisclicked((button), MOUSE_POS) == 0)
		sfRectangleShape_setFillColor(button->obj, OVER_ITEM_COLOR);
	else if (button_fly_over(button, MOUSE_POS) == 1 &&
	buttonisclicked((button), MOUSE_POS) == 1
	&& CLICK_RELEASED == sfTrue) {
		CLICK_RELEASED = sfFalse;
		return (button->callback ? button->callback(pos, game) : 84);
	} else if (!game->movement.is_moving
	&& sfRectangleShape_getFillColor(button->obj).a == 255)
		sfRectangleShape_setFillColor(button->obj, REGULAR_COLOR);
	return (0);
}

int manage_slot_buttons(sfVector2i *pos, slot_t *slot, game_t *game)
{
	if (!slot)
		return (84);
	if (slot->slot && slot->slot->obj)
		if (process_inventory_button_over(pos, slot->slot, game) != 0)
			return (84);
	if (slot->item && slot->item->obj && slot->item->obj->obj)
		if (process_inventory_button_over(pos,
		slot->item->obj, game) != 0)
			return (84);
	return (0);
}

int manage_inventory_buttons(game_t *game)
{
	sfVector2i pos = {-1, -1};

	if (slots_foreach(game, &manage_slot_buttons) != 0)
		return (84);
	if (manage_slot_buttons(&pos, &HELMET, game) != 0
	|| manage_slot_buttons(&pos, &CHEST, game) != 0
	|| manage_slot_buttons(&pos, &PANTS, game) != 0
	|| manage_slot_buttons(&pos, &GAUNTLETS, game) != 0
	|| manage_slot_buttons(&pos, &WEAPON, game) != 0)
		return (84);
	return (0);
}
