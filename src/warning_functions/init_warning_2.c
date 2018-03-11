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
	if (!text->name || !text->text || !text->font || !text->charac_size
		|| !text->x || !text->y
		|| !text->name[0] || !text->name[1]
		|| !text->text[0] || !text->text[1]
		|| !text->font[0] || !text->font[1]
		|| !text->charac_size[0] || !text->charac_size[1]
		|| !text->x[0] || !text->x[1]
		|| !text->y[0] || !text->y[1]
		|| my_fastcmp(text->name[0], TEXT_KEYWORD) == 1
		|| my_fastcmp(text->text[0], STR_KEYWORD) == 1
		|| my_fastcmp(text->font[0], FONT_KEYWORD) == 1
		|| my_fastcmp(text->charac_size[0], CHARAC_SIZE_KEYWORD) == 1
		|| my_fastcmp(text->x[0], X_KEYWORD) == 1
		|| my_fastcmp(text->y[0], Y_KEYWORD) == 1) {
		my_printf("WARNING: INVALID TEXT INIT FORMAT");
		return (84);
	}
	return (0);
}

int check_invalid_index(int index)
{
	if (index < 0 || index >= OBJS_TYPE_NB) {
		my_printf("WARNING: INDEX HAS TO STICK BETWEEN 0 AND 3 !\n");
		return (84);
	}
	return (0);
}
