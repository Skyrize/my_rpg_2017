/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** feet_particles.c created: 01/05/18
*/

#include <rpg.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Audio.h>

bool feet_particles_cond(sfSprite *particle, game_t *game)
{
	sfVector2f pos = sfSprite_getPosition(particle);
	sfVector2f spawner_pos =
		sfRectangleShape_getPosition(PLAYER_CHARACTER->obj);
	if (pos.x > spawner_pos.x + 30)
		return (true);
	if (pos.x < spawner_pos.x - 30)
		return (true);
	if (pos.y < spawner_pos.y - 30)
		return (true);
	if (pos.y > spawner_pos.y + 30)
		return (true);
	return (false);
}

particle_sys_t *init_foot_particles(game_t *game)
{
	sfIntRect spawn = (sfIntRect) {.top = 0, .left = 0,
		.height = 2, .width = 2};
	particle_sys_t *sys = create_particle_sys(spawn,
						  "RAIN_DROP", 10, game);

	sys->spawn_density = 1;
	sys->force = V2F(1, 0);
	sys->condition = feet_particles_cond;
	return (sys);
}

void update_feet_particles(game_t *game)
{
	static particle_sys_t *sys = NULL;
	sfVector2f pos;

	if (strcmp(CURRENT_BUCKET->key, "GAME") != 0)
		return;
	if (!sys)
		sys = init_foot_particles(game);
	pos = sfRectangleShape_getPosition(PLAYER_CHARACTER->obj);
	sys->spawn_zone.left = (int) pos.x + 25;
	sys->spawn_zone.top = (int) pos.y + 90;
	if (PLAYER_CHARACTER->obj_rect.rect_start.y == 300)
		sys->force = V2F(0, 3);
	else if (PLAYER_CHARACTER->obj_rect.rect_start.y == 200)
		sys->force = V2F(-3, 0);
	else if (PLAYER_CHARACTER->obj_rect.rect_start.y == 100)
		sys->force = V2F(3, 0);
	sys->activated = (bool) PLAYER_CHARACTER->obj_rect.animated;
	if (PLAYER_CHARACTER->obj_rect.rect_start.y == 100)
		sys->activated = false;
}