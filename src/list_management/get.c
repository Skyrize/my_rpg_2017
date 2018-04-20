/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

display_list_t *get_scene_from_displayed(char *asked, window_t *window)
{
	display_list_t *tmp = DISPLAYED_SCENES;

	while (tmp && my_strcmp(tmp->scene_name, asked) == 1)
		tmp = tmp->next;
	return (tmp);
}
