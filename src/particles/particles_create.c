/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** particles_create.c created: 30/04/18
*/

#include <rpg.h>
#include <SFML/Audio.h>

bool default_particle_cond(sfSprite *sprite)
{
	if (sfSprite_getPosition(sprite).y > 600)
		return (true);
	return (false);
}

void display_particle_sys(window_t *window, particle_sys_t *sys)
{
	for (int i = 0; i < sys->spawned_particles_nbr; i++) {
		sfRenderWindow_drawSprite(window->window, sys->sprite_arr[i]
			, NULL);
	}
}

void set_init_particle_pos(particle_sys_t *sys, sfSprite *sprite)
{
	sfSprite_setPosition(sprite, get_particles_spawn_pos(sys));
}

void update_particle_sys(particle_sys_t *sys)
{
	for (int i = 0; i < sys->spawned_particles_nbr; i++) {
		sfSprite_move(sys->sprite_arr[i], sys->force);
		if (sys->gravity)
			sfSprite_move(sys->sprite_arr[i], V2F(0, 2));
		if (sys->condition(sys->sprite_arr[i]))
			set_init_particle_pos(sys, sys->sprite_arr[i]);

	}
}