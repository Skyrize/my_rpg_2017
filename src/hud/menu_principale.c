/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "rpg.h"

int menu_principale(my_w_t *window)
{
	static sfBool updated = sfFalse;

	window->current = hm_get_bucket(window->scenes, HOME);
	if (clean_displayed_scenes_and_add_back(window, HOME) != 0)
		return (84);
	if (PLAYER_NAME && updated == sfFalse) {
		updated = sfTrue;
		if (update_button("NEW_GAME", "CONTINUE",
		window->current->value, window) != 0)
			return (84);
	}
	return (1);
}
