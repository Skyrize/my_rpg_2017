/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

managed_scene_t *get_scene_from_displayed(char *asked, game_t *game)
{
	managed_scene_t *tmp = MANAGED_SCENES;

	while (tmp && my_strcmp(tmp->name, asked) == 1)
		tmp = tmp->next;
	return (tmp);
}
