/*
** EPITECH PROJECT, 2017
** my_world_2017
** File description:
** ressources.c created: 01/02/18 13:32
*/

#include "../../include/my_world.h"

ressources_t *create_ressources(void)
{
	ressources_t *rsces = malloc(sizeof(ressources_t));

	create_window(rsces);
	return (rsces);
}
