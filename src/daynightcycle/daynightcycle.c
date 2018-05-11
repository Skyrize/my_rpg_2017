/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** daynightcycle.c created: 11/05/18
*/

#include <rpg.h>

int init_day_night_cycle(game_t *game)
{
	texture_t *tex = hm_get(TEXTURES_LIB, "NIGHT");

	if (!tex)
		return (1);
	game->particles->night_color = sfSprite_create();
	if (!game->particles->night_color)
		return (1);
	sfSprite_setTexture(game->particles->night_color,
			    tex->texture, sfFalse);
	return (0);
}

void update_day_night_cycle(game_t *game)
{
	sfSprite *sprite = game->particles->night_color;
	static sfClock *clock = NULL;
	sfTime time;
	sfUint8 factor = 0;
	static sfBool check = false;

	if (strcmp(CURRENT_BUCKET->key, "GAME") != 0)
		return;
	if (!clock) {
		clock = sfClock_create();
		if (!clock)
			return;
	}
	time = sfClock_getElapsedTime(clock);
	factor = (sfUint8) (sin(((double)sfTime_asSeconds(time)) / 45) * 215);
	if (factor == 0 && check == true) {
		sfClock_restart(clock);
		check = false;
	} else if (factor == 213 && check == false)
		check = true;
	sfSprite_setColor(sprite, sfColor_fromRGBA(255, 255, 255, factor));
	sfRenderWindow_drawSprite(game->window->window, sprite, NULL);
}