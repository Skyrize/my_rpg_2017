/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "rpg.h"


myfunc_t g_tab[] =
{
	{"START_NEW_GAME", new_game},
	{"OPTION", option},
	{"CREDITS", credits},
	{"CARACTERISTIQUE", caracteristique},
	{"INVENTAIRE", inventaire},
	{"MAP", map},
	{"NEW_GAME", new_game},
	{"PAUSE", pause},
	{"QUETES", quetes},
	{"QUIT", quit},
	{"RE_LOAD", re_load},
	{"resume", resume},
	{"SAVE", save},
	{0, 0}
};

/*
int init_callback_obj(my_w_t *window)
{
	int i = 0;

	while (g_tab[i].balise != 0) {
		if (!g_tab[i].balise || ![MANQUE UN ARGS])
			return (84);
		if (my_strcmp(g_tab[i].balise, [MANQUE UN ARGS]) == 0)
			[MANQUE UN ARGS] = g_tab[i].instruction;
		i += 1;
	}
	return (0);
}*/
