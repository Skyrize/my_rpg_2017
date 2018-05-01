/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** rain.c created: 01/05/18
*/

#include <rpg.h>

particle_sys_t *init_rain(game_t *game)
{
	sfIntRect spawn = (sfIntRect) {.top = 0, .left = 0,
				.height = 2, .width = 800};
	particle_sys_t *sys = create_particle_sys(spawn,
		"RAIN_DROP", 700, game);
	sys->spawn_density = 2;
	sys->force = V2F(0, 4);
	sys->sys_name = "main_rain";
	return (sys);
}

void rain(game_t *game, window_t *window)
{
	static particle_sys_t *sys = NULL;
	static texture_t *tex = NULL;
	static sfSprite *bg = NULL;

	if (!sys) {
		sys = init_rain(game);
		tex = hm_get(TEXTURES_LIB, "BG_INTERFACE");
		bg = sfSprite_create();
		sfSprite_setTexture(bg, tex->texture, sfFalse);
		sfSprite_setColor(bg, sfColor_fromRGBA(255, 255, 255, 150));
		game->particles->rain = sys;
	}
	if (sys->activated)
		sfRenderWindow_drawSprite(window->window, bg, NULL);
}