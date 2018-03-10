/*
** EPITECH PROJECT, 2017
** PSU_minishell1_2017
** File description:
** (enter)
*/
#include "../../include/my.h"

int my_fastcmp(char const *s1, char const *s2)
{
	if (!s1 || !s2 || my_strlen(s1) < 1 || my_strlen(s2) < 1)
		return (1);
	for (int i = 0; s1[i] && s2[i]; i++) {
		if (s1[i] != s2[i]) {
			return (1);
		}
	}
	return (0);
}
