/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

static const key_word_t init_words[] = {{"SCENE", 0, &get_a_scene},
{"LIST", 0, &get_a_list},
{"INDEX", 0, &get_an_index},
{"OBJ", 3, &get_an_obj},
{"TEXT", 5, &get_a_text},
{"MUSIC", 0, &get_a_music},
{NULL, 0, NULL}};

int init_scenes_from_pcf(char **infos, my_w_t *window)
{
	char **type = my_str_to_word_array(infos[0], '=');
	static hashmap_t *current_list;
	unsigned int i = 0;

	if (check_missing_args_for_key_word(type) != 0)
		return (84);
	for (; init_words[i].key_word; i++) {
		if (check_missing_sub_keyword(init_words[i].key_word,
			init_words[i].nb_sub_keywords, infos) != 0)
			return (84);
		if (my_fastcmp(init_words[i].key_word, type[0]) == 0) {
			window->error_no = init_words[i].fptr(infos, type,
				&current_list, window);
			break;
		}
	}
	if (check_invalid_key_word(init_words[i].key_word, type[0],
		window->error_no) != 0)
		return (84);
	return (0);
}

int init_textures_lib_from_pcf(char **infos, my_w_t *window)
{
	sfTexture *texture = sfTexture_createFromFile(infos[0], NULL);

	if (!texture)
		return (84);
	if (check_already_existing_texture(window->textures_lib, infos[1]) != 0)
		return (84);
	hm_add(window->textures_lib, infos[1], texture);
	return (0);
}

int init_audio_lib_from_pcf(char **infos, my_w_t *window)
{
	sfMusic *music = sfMusic_createFromFile(infos[0]);

	if (!music)
		return (84);
	if (check_already_existing_audio(window->audio_lib, infos[1]) != 0)
		return (84);
	hm_add(window->audio_lib, infos[1], music);
	return (0);
}

int init_fonts_lib_from_pcf(char **infos, my_w_t *window)
{
	sfFont *font = sfFont_createFromFile(infos[0]);

	if (!font)
		return (84);
	if (check_already_existing_font(window->fonts_lib, infos[1]) != 0)
		return (84);
	hm_add(window->fonts_lib, infos[1], font);
	return (0);
}
