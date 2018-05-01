/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** particle_spawn.c created: 01/05/18
*/

#include <rpg.h>
#include <SFML/Graphics/Rect.h>

static int get_rnd(int min, int max)
{
	return (rand() % (max - min + 1) + min);
}

sfVector2f get_particles_spawn_pos(particle_sys_t *sys)
{
	int x = get_rnd(sys->spawn_zone.left,
			  sys->spawn_zone.left + sys->spawn_zone.width);
	int y = get_rnd(sys->spawn_zone.top,
			  sys->spawn_zone.top + sys->spawn_zone.height);
	sfVector2f res = (sfVector2f) {.x = x, .y = y};

	return (res);
}

void init_particle_position(particle_sys_t *sys)
{
	int i = sys->spawned_particles_nbr;
	int max_i = sys->spawned_particles_nbr + sys->spawn_density;

	if (!sys->sprite_arr)
		return;
	if (i == sys->particle_nbr) {
		return;
	}
	if (max_i > sys->particle_nbr)
		max_i = sys->particle_nbr;
	for (; i < max_i; i++) {
		if (!sys->sprite_arr[i])
			continue;
		sfVector2f a = get_particles_spawn_pos(sys);
		printf("pos: %f %f\n", a.x, a.y);
		sfSprite_setPosition(sys->sprite_arr[i],
				     a);
	}
	sys->spawned_particles_nbr = max_i;
}