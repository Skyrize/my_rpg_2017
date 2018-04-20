/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

display_list_t *get_scene_from_displayed(char *asked, my_w_t *window)
{
	display_list_t *tmp = window->displayed_scenes;

	while (tmp && my_strcmp(tmp->scene_name, asked) == 1)
		tmp = tmp->next;
	return (tmp);
}
