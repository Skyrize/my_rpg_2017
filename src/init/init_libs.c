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
	get_infos_t infos = {"pcf/sounds.pcf", "-", &init_audio_lib_from_pcf};

	window->audio_lib = hm_create(64, &sfMusic_destroy);
	if (analyse_my_project_config_file(window, &infos) != 0) {
		my_printf("WARNING: ERROR IN AUDIO LIB INIT !\n");
		return (84);
	}
	return (0);
}

int init_my_textures_lib(my_w_t *window)
{
	get_infos_t infos = {"pcf/textures.pcf", "-",
	&init_textures_lib_from_pcf};

	window->textures_lib = hm_create(512, &sfTexture_destroy);
	if (analyse_my_project_config_file(window, &infos) != 0) {
		my_printf("WARNING: ERROR IN TEXTURES LIB INIT !\n");
		return (84);
	}
	return (0);
}

int init_my_fonts_lib(my_w_t *window)
{
	get_infos_t infos = {"pcf/fonts.pcf", "-",
	&init_fonts_lib_from_pcf};

	window->fonts_lib = hm_create(512, &sfFont_destroy);
	if (analyse_my_project_config_file(window, &infos) != 0) {
		my_printf("WARNING: ERROR IN FONTS LIB INIT !\n");
		return (84);
	}
	return (0);
}
