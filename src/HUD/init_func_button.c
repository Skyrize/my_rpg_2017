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
	{"INVENTAIRE", inventory},
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
