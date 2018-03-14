/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int scene_init(scene_t **value)
{
	*value = malloc(sizeof(scene_t));
	if (!*value)
		return (84);
	for (int i = 0; i != OBJS_TYPE_NB; i++) {
		(*value)->objs[i] = hm_create(64, &obj_destroy);
		if (!(*value)->objs[i])
			return (84);
	}
	(*value)->texts = hm_create(64, &sfText_destroy);
	if (!(*value)->texts)
		return (84);
	(*value)->music = NULL;
	return (0);
}

int init_scene_lists(char *scene_name, my_w_t *window)
{
	bucket_t *scene = hm_get_bucket(window->scenes, scene_name);
	scene_t *value;

	if (scene != NULL) {
		my_printf("WARNING: TWO SCENES WITH THE SAME NAME!\n");
		return (84);
	}
	if (scene_init(&value) != 0)
		return (84);
	hm_add(window->scenes, scene_name, value);
	return (0);
}

int init_my_scenes(my_w_t *window)
{

	get_infos_t infos = {"pcf/scenes.pcf", INIT_INDICATOR,
	&init_scenes_from_pcf};

	window->scenes = hm_create(16, &scenes_destroy);
	if (analyse_my_project_config_file(window, &infos) != 0) {
		my_printf("WARNING: ERROR IN SCENES LIST INIT !\n");
		return (84);
	}
	return (0);
}
