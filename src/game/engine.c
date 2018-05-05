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
		&& event == sfFalse && manager_tab[i].fptr)
			return (manager_tab[i].fptr(window, game));
		else if (my_strcmp(scene->name, manager_tab[i].balise) == 0
		&& event == sfTrue && manager_tab[i].event)
			return (manager_tab[i].event(window, game));
	}
	return (0);
}

int process_managed_events(window_t *window, game_t *game)
{
	int my_errno = 0;

	for (managed_scene_t *tmp = MANAGED_SCENES; tmp; tmp = tmp->next) {
		my_errno = manage(sfTrue, tmp, window, game);
		if (my_errno != 0)
			return (my_errno);
	}
	return (0);
}

int analyse_events(window_t *window, game_t *game)
{
	int my_errno = 0;

	while (sfRenderWindow_pollEvent(window->window, &window->event)) {
		if (window->event.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		if (window->event.type == sfEvtMouseButtonReleased)
			CLICK_RELEASED = sfTrue;
		my_errno = process_managed_events(window, game);
		if (my_errno != 0)
			return (my_errno);
	}
	return (0);
}

int manage_scene(managed_scene_t *scene, window_t *window, game_t *game)
{
	int my_errno = 0;

	if (display_scene(scene, window, game) != 0)
		return (84);
	my_errno = manage(sfFalse, scene, window, game);
	if (my_errno != 0)
		return (my_errno);
	my_errno = manage_buttons(scene, window, game);
	if (my_errno != 0)
		return (my_errno);
	return (0);
}

int process_engine(window_t *window, game_t *game)
{
	managed_scene_t *tmp = MANAGED_SCENES;
	int my_errno = 0;

	MOUSE_POS = sfMouse_getPosition((const sfWindow *)window->window);
	my_errno = analyse_events(window, game);
	if (my_errno == 1) {
		return (0);
	} else if (my_errno == 84)
		return (84);
	while (tmp) {
		my_errno = manage_scene(tmp, window, game);
		if (my_errno == 1) {
			return (0);
		} else if (my_errno == 84)
			return (84);
		tmp = tmp->next;
	}
	return (my_errno);
}
