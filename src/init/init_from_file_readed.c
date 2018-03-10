/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int init_fonts_lib_from_pcf(char **infos, my_w_t *window)
{
	sfFont *font = sfFont_createFromFile(infos[0]);

	if (!font)
		return (84);
	hm_add(window->fonts_lib, infos[1], font);
	return (0);
}

int init_obj_and_texts_from_pcf(char **infos, my_w_t *window,
	char **type, hashmap_t *current_list)
{
	if (my_fastcmp(type[0], "OBJ") == 0)
		if (init_an_obj(infos, window, current_list) != 0)
			return (84);
	if (my_fastcmp(type[0], "TEXT") == 0)
		if (init_a_text(infos, window, current_list) != 0)
			return (84);
	return (0);
}

int init_scenes_and_objs_from_pcf(char **infos, my_w_t *window)
{
	char **type = my_str_to_word_array(infos[0], '=');
	static scene_t *current_scene = NULL;
	static hashmap_t *current_list = NULL;

	if (!type)
		return (84);
	if (my_fastcmp(type[0], "SCENE") == 0) {
		if (init_scene_lists(type[1], window) != 0)
			return (84);
		current_scene = hm_get(window->scenes, type[1]);
	}
	if (my_fastcmp(type[0], "INDEX") == 0)
		current_list = current_scene->objs[my_getnbr(type[1])];
	if (my_fastcmp(infos[0], "LIST=TEXTS") == 0)
		current_list = current_scene->texts;
	if (init_obj_and_texts_from_pcf(infos, window, type, current_list) != 0)
		return (84);
	return (0);
}

int init_textures_lib_from_pcf(char **infos, my_w_t *window)
{
	sfTexture *texture = sfTexture_createFromFile(infos[0], NULL);

	if (!texture)
		return (84);
	hm_add(window->textures_lib, infos[1], texture);
	return (0);
}

int init_audio_lib_from_pcf(char **infos, my_w_t *window)
{
	sfMusic *music = sfMusic_createFromFile(infos[0]);

	if (!music)
		return (84);
	hm_add(window->audio_lib, infos[1], music);
	return (0);
}
