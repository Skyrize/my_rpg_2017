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

particle_sys_t *create_particle_sys(sfIntRect spawn, char *tex_name,
				    int particle_nbr, game_t *game)
{
	particle_sys_t *ret = malloc(sizeof(*ret));
	texture_t *tex = hm_get(TEXTURES_LIB, tex_name);

	if (!ret || !tex)
		return (NULL);
	ret->texture = tex->texture;
	ret->spawn_zone = spawn;
	ret->particle_nbr = particle_nbr;
	ret->sprite_arr = malloc(sizeof(sfSprite *) * particle_nbr + 1);
	for (int i = 0; i < ret->particle_nbr; i++) {
		ret->sprite_arr[i] = sfSprite_create();
		sfSprite_setTexture(ret->sprite_arr[i], ret->texture, NULL);
	}
	ret->sprite_arr[particle_nbr] = NULL;
	ret->condition = default_particle_cond;
	ret->force = V2F(1, 0);
	ret->gravity = false;
	ret->sys_name = tex_name;
	return (ret);
}

void display_particle_sys(window_t *window, particle_sys_t *sys)
{
	for (int i = 0; i < sys->particle_nbr; i++) {
		sfRenderWindow_drawSprite(window->window, sys->sprite_arr[i]
			, NULL);
	}
}

void update_particle_sys(particle_sys_t *sys)
{
	for (int i = 0; i < sys->particle_nbr; i++) {
		sfSprite_move(sys->sprite_arr[i], sys->force);
		if (sys->gravity)
			sfSprite_move(sys->sprite_arr[i], V2F(0, 2));
	}
}