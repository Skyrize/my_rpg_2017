/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

scene_t *scene_init(int priority)
{
	scene_t *value = malloc(sizeof(scene_t));

	if (!value)
		return (NULL);
	for (int i = 0; i != OBJS_TYPE_NB; i++) {
		value->objs[i] = hm_create(64, &obj_destroy);
		if (!value->objs[i])
			return (NULL);
	}
	value->texts = hm_create(64, &sfText_destroy);
	if (!value->texts)
		return (NULL);
	value->music = NULL;
	value->priority = priority;
	return (value);
}

int init_scene_lists(char **infos, my_w_t *window)
{
	char **name = my_str_to_word_array(infos[0], KEYWORD_SEPARATOR_CHAR);
	char **priority = my_str_to_word_array(infos[1],
		KEYWORD_SEPARATOR_CHAR);
	bucket_t *scene;
	scene_t *value;

	if (!name || !priority)
		return (84);
	scene = hm_get_bucket(window->scenes, name[1]);
	if (check_already_existing_scene(scene, name[1]) != 0)
		return (84);
	value = scene_init(my_getnbr(priority[1]));
	if (!value)
		return (84);
	hm_add(window->scenes, name[1], value);
	free_char_2d(name);
	free_char_2d(priority);
	return (0);
}

int init_my_scenes(my_w_t *window)
{
	const key_word_t scene_keys[] = {
	{"SCENE", 1, &get_a_scene, (char *[]) {"PRIORITY", NULL}},
	{"LIST", 0, &get_a_list, NULL},
	{"INDEX", 0, &get_an_index, NULL},
	{"OBJ", 3, &get_an_obj,
		(char *[]) {"TEXTURE", "X", "Y", NULL}},
	{"TEXT", 5, &get_a_text,
		(char *[]) {"STR", "FONT", "CHARAC_SIZE", "X", "Y", NULL}},
	{"MUSIC", 0, &get_a_music, NULL},
	{NULL, 0, NULL, NULL}};
	get_infos_t infos = {"pcf/scenes.pcf", INIT_INDICATOR, scene_keys,
	&list_savior};

	window->scenes = hm_create(16, &scenes_destroy);
	if (analyse_my_project_config_file(window, &infos) != 0) {
		my_printf("WARNING: ERROR IN SCENES LIST INIT !\n");
		return (84);
	}
	return (0);
}
