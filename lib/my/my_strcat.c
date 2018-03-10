/*
** EPITECH PROJECT, 2017
** my str cat
** File description:
** concatenates two strings
*/
#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
	char *new_str = malloc(sizeof(char)
	* (my_strlen(dest) + my_strlen(src) + 1));
	int x = 0;

	if (!new_str)
		return (NULL);
	for (int i = 0; dest[i]; i++, x++) {
		new_str[x] = dest[i];
	}
	for (int i = 0; src[i]; i++, x++) {
		new_str[x] = src[i];
	}
	new_str[x] = 0;
	return (new_str);
}
