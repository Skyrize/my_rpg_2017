/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** init_particles.c created: 08/05/18
*/

#include <rpg.h>

int init_particles(game_t *game)
{
	game->particles = malloc(sizeof(particles_t));

	if (!game->particles)
		return (1);
	game->particles->rain = NULL;
	game->particles->rain_background = NULL;
	init_rain(game);
	return (0);
}