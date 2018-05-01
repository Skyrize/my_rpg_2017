/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** feet_particles.c created: 01/05/18
*/

#include <rpg.h>

particle_sys_t *init_foot_particles(game_t *game)
{
	sfIntRect spawn = (sfIntRect) {.top = 0, .left = 0,
		.height = 2, .width = 2};
	particle_sys_t *sys = create_particle_sys(spawn,
						  "RAIN_DROP", 10, game);
	sys->spawn_density = 1;
	sys->force = V2F(1, 1);
	sys->gravity = true;
	return (sys);
}