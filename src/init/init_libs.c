/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int init_my_audio_lib(my_w_t *window)
{
	const key_word_t audio_keys[] = {
	{"AUDIO", 1, &get_an_audio, (char *[]) {"FILEPATH", NULL}},
	{NULL, 0, NULL, NULL}};
	get_infos_t infos = {"pcf/sounds.pcf", INIT_INDICATOR, audio_keys,
	&list_savior};

	window->audio_lib = hm_create(64, &sfMusic_destroy);
	if (analyse_my_project_config_file(window, &infos) != 0) {
		my_printf("WARNING: ERROR IN AUDIO LIB INIT !\n");
		return (84);
	}
	return (0);
}

int init_my_fonts_lib(my_w_t *window)
{
	const key_word_t font_keys[] = {
	{"FONT", 1, &get_a_font, (char *[]) {"FILEPATH", NULL}},
	{NULL, 0, NULL, NULL}};
	get_infos_t infos = {"pcf/fonts.pcf", INIT_INDICATOR, font_keys,
	&list_savior};

	window->fonts_lib = hm_create(16, &sfFont_destroy);
	if (analyse_my_project_config_file(window, &infos) != 0) {
		my_printf("WARNING: ERROR IN FONTS LIB INIT !\n");
		return (84);
	}
	return (0);
}

int init_my_textures_lib(my_w_t *window)
{
	const key_word_t texture_keys[] = {
	{"TEXTURE", 0, &get_a_texture, NULL},
	{"FILEPATH", 0, &get_a_texture_filepath, NULL},
	{"ANIMATED", 0, &get_an_animated, NULL},
	{"RECT_VALUES", 4, &get_a_rect_values,
		(char *[]) {"LEFT", "TOP", "WIDTH", "HEIGHT", NULL}},
	{"RECT_START", 2, &get_a_rect_start_values,
	(char *[]) {"X", "Y", NULL}},
	{"RECT_MAX", 2, &get_a_rect_max_values, (char *[]) {"X", "Y", NULL}},
	{"RECT_OFFSET", 2, &get_a_rect_max_offset, (char *[]) {"X", "Y", NULL}},
	{NULL, 0, NULL, NULL}};
	get_infos_t infos = {"pcf/textures.pcf", INIT_INDICATOR, texture_keys,
	&list_savior};

	window->textures_lib = hm_create(512, &texture_destroy);
	if (analyse_my_project_config_file(window, &infos) != 0) {
		my_printf("WARNING: ERROR IN TEXTURES LIB INIT !\n");
		return (84);
	}
	return (0);
}
