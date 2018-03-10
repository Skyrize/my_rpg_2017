/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "../../include/my.h"

int my_arraycmp(unsigned int *arr1, unsigned int *arr2)
{
	for (int i = 1; i != 13; i++) {
		if (arr1[i] != arr2[i])
			return (1);
	}
	return (0);
}
