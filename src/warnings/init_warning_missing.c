/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_invalid_window_init(int error_no)
{
	if (error_no != 0) {
		my_printf("WARNING: ERROR IN INITIALISATION\n");
		return (84);
	}
	return (0);
}

int check_missing_sub_keyword(char *keyword, int nb_keyword, char **subwords_tab)
{
	int i = 0;

	for (; subwords_tab[i]; i++);
	if (my_fastcmp(keyword, subwords_tab[0]) == 0
	&& i - 1 != nb_keyword) {
		my_printf("WARNING: %d ARGUMENTS FOR KEYWORD '%s'",
		nb_keyword, keyword);
		my_printf(" ARE REQUIRED !\n");
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

int check_undefined_scene(scene_t *current_scene, char *asked_list)
{
	if (!current_scene) {
		my_printf("WARNING: YOU ASKED FOR '%s' BUT SCENE ISN'T DEFINED !\n",
		asked_list);
		return (84);
	}
	return (0);
}
