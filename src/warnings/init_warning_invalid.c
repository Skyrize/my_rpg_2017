/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

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
		|| my_fastcmp(text->text[0], STR_KEYWORD) == 1
		|| my_fastcmp(text->font[0], FONT_KEYWORD) == 1
		|| my_fastcmp(text->charac_size[0], CHARAC_SIZE_KEYWORD) == 1
		|| my_fastcmp(text->x[0], X_KEYWORD) == 1
		|| my_fastcmp(text->y[0], Y_KEYWORD) == 1) {
		my_printf("WARNING: INVALID TEXT INIT FORMAT !\n");
		return (84);
	}
	return (0);
}

int check_invalid_obj_init(obj_infos_t *obj)
{
	if (!obj->name || !obj->type || !obj->x || !obj->y
		|| !obj->name[0] || !obj->name[1]
		|| !obj->type[0] || !obj->type[1]
		|| !obj->x[0] || !obj->x[1]
		 || !obj->y[0] || !obj->y[1]
		|| my_fastcmp(obj->type[0], TEXTURE_KEYWORD) == 1
		|| my_fastcmp(obj->x[0], X_KEYWORD) == 1
		|| my_fastcmp(obj->y[0], Y_KEYWORD) == 1) {
		my_printf("WARNING: INVALID OBJ INIT\n");
		return (84);
	}
	return (0);
}

int check_invalid_index(int index)
{
	if (index < 0 || index >= OBJS_TYPE_NB) {
		my_printf("WARNING: INDEX HAS TO STICK BETWEEN 0 AND %d !\n",
		OBJS_TYPE_NB);
		return (84);
	}
	return (0);
}

int check_invalid_key_word(char *last_word_used, char *key_word,
	int error_no)
{
	if (error_no != 0)
		return (84);
	if (last_word_used == NULL) {
		my_printf("WARNING: '%s' ISN'T A VALID KEYWORD !\n", key_word);
		return (84);
	}
	return (0);
}

int check_invalid_file(int fd, char *filename)
{
	if (fd == -1) {
		my_printf("WARNING: CAN'T FIND '%s' FILE !\n", filename);
		return (84);
	}
	return (0);
}
