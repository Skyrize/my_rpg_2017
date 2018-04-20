/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int button_display_hide_scene(char *scene_name,
				void (*update)(), my_w_t *window)
{
	display_list_t *displayed_scene = get_scene_from_displayed(scene_name,
	window);
	scene_t *scene = hm_get(SCENES, scene_name);

	if (!scene)
		return (84);
	if (displayed_scene) {
		window->current = hm_get_bucket(SCENES, "GAME");
		clean_displayed_scene_name(window, scene_name);
	} else {
		window->current = hm_get_bucket(SCENES, scene_name);
		if (update)
			update(scene, window);
		if (add_scene_to_display_list(hm_get_bucket(SCENES,
			scene_name), window) != 0)
			return (84);
	}
	return (1);
}
