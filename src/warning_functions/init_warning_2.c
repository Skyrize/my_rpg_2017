/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_invalid_key_word(char *last_word_used, char *key_word)
{
	if (last_word_used == NULL) {
		my_printf("WARNING: '%s' ISN'T A VALID KEYWORD !\n", key_word);
		return (84);
	}
	return (0);
}

int check_invalid_music(sfMusic *music, char *music_name)
{
	if (!music) {
		my_printf("WARNING: CAN'T FIND MUSIC '%s' AT INITIALISATION!\n",
		music_name);
		return (84);
	}
	return (0);
}

int check_missing_args_for_key_word(char **args)
{
	if (!args) {
		my_printf("WARNING: MALLOC FAILED FOR WORD TAB !\n");
		return (84);
	}
	if (!args[0]) {
		my_printf("WARNING: MALLOC FAILED FOR WORD TAB[0] !\n");
		return (84);
	}
	if (!args[1]) {
		my_printf("WARNING: KEY WORD MUST HAVE ARGUMENT AFTER '=' !\n");
		return (84);
	}
	return (0);
}

int check_invalid_text_init(text_infos_t *text)
{
	if (!text->text || !text->text_font || !text->text_charac_size
		|| !text->text_x || !text->text_y || !text->text[0]
		|| !text->text_font[0] || !text->text_charac_size[0]
		|| !text->text_x[0] || !text->text_y[0] || !text->text[1]
		|| !text->text_font[1] || !text->text_charac_size[1]
		|| !text->text_x[1] || !text->text_y[1]
		|| my_fastcmp(text->text[0], "TEXT") == 1
		|| my_fastcmp(text->text_font[0], "FONT") == 1
		|| my_fastcmp(text->text_charac_size[0], "CHARAC_SIZE") == 1
		|| my_fastcmp(text->text_x[0], "X") == 1
		|| my_fastcmp(text->text_y[0], "Y") == 1) {
		my_printf("WARNING: INVALID TEXT INIT FORMAT");
		return (84);
	}
	return (0);
}
