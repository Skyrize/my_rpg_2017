/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** free_system.c created: 01/05/18
*/

#include <rpg.h>

void free_particle_sys(particle_sys_t *sys)
{
	for (int i = 0; i < sys->particle_nbr; i++) {
		sfSprite_destroy(sys->sprite_arr[i]);
	}
	free(sys->sprite_arr);
	sys->sprite_arr = NULL;
}

void remove_particle_sys(particle_sys_t *sys)
{
	remove_particle_sys_by_id(sys->sys_id);
}