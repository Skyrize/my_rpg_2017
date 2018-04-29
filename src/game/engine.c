/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** engine.c
*/

#include "rpg.h"

static const manager_t manager_tab[] =
{
	{"BATTLE", battle_lobby},
	{"GAME", game_lobby},
	{"INVENTORY", inventory_lobby},
	{NULL, NULL},
};

void get_time(ctime_t *clocker)
{
	clocker->timer = sfClock_getElapsedTime(clocker->clock);
	clocker->seconds = clocker->timer.microseconds / 1000000.0;
}

int manage(managed_scene_t *scene, window_t *window, game_t *game)
{
	for (int i = 0; manager_tab[i].balise; i++) {
		if (my_strcmp(scene->name, manager_tab[i].balise) == 0)
			return (manager_tab[i].fptr(window, game));
	}
	analyse_events(window, game);
	return (0);
}

int process_engine(window_t *window, game_t *game)
{
	managed_scene_t *tmp = MANAGED_SCENES;
	int my_errno = 0;

	MOUSE_POS = sfMouse_getPosition((const sfWindow *)window->window);
	while (tmp) {
		if (display_scene(tmp, window, game) != 0)
			return (84);
		if (manage_buttons(tmp, window, game) != 0)
			return (84);
		my_errno = manage(tmp, window, game);
		if (my_errno != 0)
			break;
		tmp = tmp->next;
	}
	return (my_errno);
}
