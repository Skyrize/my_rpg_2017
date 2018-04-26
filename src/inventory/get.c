/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** get.c
*/

#include "rpg.h"

int slots_foreach_horizontaly(int y, game_t *game, int (*fptr)())
{
	int my_errno = 0;

	for (int x = 0; x != INVENTORY_SIZE_X; x++) {
		my_errno = fptr(&V2I(x, y), &ITEMS[y][x], game);
		if (my_errno != 0)
			break;
	}
	return (my_errno);
}

int slots_foreach(game_t *game, int (*fptr)())
{
	int my_errno = 0;

	if (!game) {
		my_printf("ERROR: YOU MUST PASS GAME \
		STRUCT TO ITEMS_FOREACH !\n");
		return (84);
	}
	for (int y = 0; y != INVENTORY_SIZE_Y; y++) {
		my_errno = slots_foreach_horizontaly(y, game, fptr);
		if (my_errno != 0)
			break;
	}
	return (my_errno);
}
int items_foreach_horizontaly(int y, game_t *game,
				window_t *window, int (*fptr)())
{
	int my_errno = 0;

	for (int x = 0; x != INVENTORY_SIZE_X; x++) {
		if (!window) {
			my_errno = fptr(&ITEMS[y][x], game);
		} else {
			my_errno = fptr(&ITEMS[y][x], window, game);
		}
		if (my_errno != 0)
			break;
	}
	return (my_errno);
}

int items_foreach(game_t *game, window_t *window, int (*fptr)())
{
	int my_errno = 0;

	if (!game) {
		my_printf("ERROR: YOU MUST PASS GAME \
		STRUCT TO ITEMS_FOREACH !\n");
		return (84);
	}
	for (int y = 0; y != INVENTORY_SIZE_Y; y++) {
		my_errno = items_foreach_horizontaly(y, game, window, fptr);
		if (my_errno != 0)
			break;
	}
	return (my_errno);
}

item_t *copy_item_lib(char *name, hashmap_t *items_lib)
{
	item_t *item = hm_get(items_lib, name);
	item_t *new = NULL;

	if (check_unexisting_item(item, name) != 0)
		return (NULL);
	new = create_item(&(item_data_t){name, item->obj, item->quest,
					item->consumable, item->stats});
	if (!new)
		return (NULL);
	return (new);
}