/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** rain.c created: 01/05/18
*/

#include <rpg.h>

void init_rain(game_t *game)
{
	sfIntRect spawn = (sfIntRect) {.top = 0, .left = 0,
				.height = 2, .width = 800};
	particle_sys_t *sys = create_particle_sys(spawn,
		"RAIN_DROP", 700, game);
	sys->spawn_density = 2;
	sys->force = V2F(0, 2);
}