/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

char *found_icon(my_w_t *window)
{
	char *icon_tab[4][2] = {
	{"Avelus", "AVELUS_ICON"},
	{"Varyan", "VARYAN_ICON"},
	{"Jaina", "JAINA_ICON"},
	{NULL, NULL}};

	for (int i = 0 ; icon_tab[i][1] != NULL ; i++) {
		if (my_strcmp(icon_tab[i][0], PLAYER_NAME) == 0)
			return (icon_tab[i][1]);
	}
	return (NULL);
}

int update_element(my_w_t *window)
{
	scene_t *curr_scene = hm_get(window->scenes, "HEALTH_HUD");
	obj_t *player_icon = NULL;
	bucket_t *check = NULL;
	sfTexture *new_texture;
	char *name_texture = found_icon(window);

	if (!curr_scene || !curr_scene->objs || !name_texture)
		return (84);
	check = hm_get(window->textures_lib, name_texture);
	if (!check || !check->value)
		return (84);
	new_texture = check->value;
	player_icon = hm_get(curr_scene->objs, "CHARACTERISTIC");
	if (!player_icon)
		return (84);
	sfRectangleShape_setTexture(player_icon->obj, new_texture, sfTrue);
	return (0);
}

int game(my_w_t *window)
{
	window->current = hm_get_bucket(window->scenes, "GAME");

	update_element(window);
	if (clean_displayed_scenes_and_add_back(window, "GAME") != 0)
		return (84);
	if (add_scene_to_display_list(
		hm_get_bucket(window->scenes, "HEALTH_HUD"), window) != 0)
		return (84);
	if (add_scene_to_display_list(
		hm_get_bucket(window->scenes, "AREA_HUD"), window) != 0)
	return (1);
}

int resume(my_w_t *window)
{
	window->current = hm_get_bucket(window->scenes, "GAME");
	clean_displayed_scene_name(window, PAUSE_GAME);
	return (1);
}
