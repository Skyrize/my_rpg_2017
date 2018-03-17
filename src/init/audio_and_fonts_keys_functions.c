/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int get_an_audio(char **infos, char **type,
	hashmap_t **current_list, my_w_t *window)
{
	sfMusic *audio;
	char **audio_path = my_str_to_word_array(infos[1],
		KEYWORD_SEPARATOR_CHAR);

	*current_list = window->audio_lib;
	audio = hm_get(*current_list, type[1]);
	if (check_already_existing_audio(audio, type[1]) != 0)
		return (84);
	audio = sfMusic_createFromFile(audio_path[1]);
	if (!audio)
		return (84);
	hm_add(window->audio_lib, type[1], audio);
	free_char_2d(audio_path);
	return (0);
}

int get_a_font(char **infos, char **type,
	hashmap_t **current_list, my_w_t *window)
{
	sfFont *font;
	char **font_path = my_str_to_word_array(infos[1],
		KEYWORD_SEPARATOR_CHAR);

	*current_list = window->fonts_lib;
	font = hm_get(*current_list, type[1]);
	if (check_already_existing_font(font, type[1]) != 0)
		return (84);
	font = sfFont_createFromFile(font_path[1]);
	if (!font)
		return (84);
	hm_add(window->fonts_lib, type[1], font);
	free_char_2d(font_path);
	return (0);
}