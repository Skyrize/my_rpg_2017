/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** engine.c
*/

#include "rpg.h"

static const manager_t manager_tab[] =
{
	{"BATTLE", battle_lobby, battle_events},
	{"GAME", game_lobby, game_events},
	{"INVENTORY", inventory_lobby, NULL},
	{NULL, NULL, NULL},
};

int manage(sfBool event, managed_scene_t *scene, window_t *window, game_t *game)
{
	for (int i = 0; manager_tab[i].balise; i++) {
		if (my_strcmp(scene->name, manager_tab[i].balise) == 0
		&& event == sfFalse)
			return (manager_tab[i].fptr(window, game));
		else if (my_strcmp(scene->name, manager_tab[i].balise) == 0
		&& event == sfTrue)
			return (manager_tab[i].event(window, game));
	}
	return (0);
}

int process_managed_events(window_t *window, game_t *game)
{
	for (managed_scene_t *tmp = MANAGED_SCENES; tmp; tmp = tmp->next) {
		if (manage(sfTrue, tmp, window, game) != 0)
			return (84);
	}
	return (0);
}

int analyse_events(window_t *window, game_t *game)
{
	while (sfRenderWindow_pollEvent(window->window, &window->event)) {
		if (window->event.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		if (window->event.type == sfEvtMouseButtonReleased)
			CLICK_RELEASED = sfTrue;
		if (process_managed_events(window, game) != 0)
			return (84);
	}
	return (0);
}

int process_engine(window_t *window, game_t *game)
{
	managed_scene_t *tmp = MANAGED_SCENES;
	int my_errno = 0;

	MOUSE_POS = sfMouse_getPosition((const sfWindow *)window->window);
	if (analyse_events(window, game) != 0)
		return (84);
	while (tmp) {
		if (display_scene(tmp, window, game) != 0)
			return (84);
		if (manage_buttons(tmp, window, game) != 0)
			return (84);
		my_errno = manage(sfFalse, tmp, window, game);
		if (my_errno != 0)
			break;
		tmp = tmp->next;
	}
	return (my_errno);
}
