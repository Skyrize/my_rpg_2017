/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"
extern key_word_t init_words[];

int init_fonts_lib_from_pcf(char **infos, my_w_t *window)
{
	sfFont *font = sfFont_createFromFile(infos[0]);

	if (!font)
		return (84);
	hm_add(window->fonts_lib, infos[1], font);
	return (0);
}

int init_scenes_from_pcf(char **infos, my_w_t *window)
{
	char **type = my_str_to_word_array(infos[0], '=');
	static hashmap_t *current_list;
	unsigned int i = 0;

	if (check_missing_args_for_key_word(type) != 0)
		return (84);
	for (; init_words[i].key_word; i++) {
		if (my_fastcmp(init_words[i].key_word, type[0]) == 0) {
			window->error_no = init_words[i].fptr(infos, type,
				&current_list, window);
			break;
		}
	}
	if (window->error_no != 0)
		return (84);
	if (check_invalid_key_word(init_words[i].key_word, type[0]) != 0)
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
