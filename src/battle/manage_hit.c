/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "rpg.h"

int re_init_at_initial(sfText *hit)
{
	if (sfText_getPosition(hit).y <= -300) {
		sfText_setCharacterSize(hit, 90);
		sfText_setPosition(hit, (sfVector2f){500, 300});
		sfText_setString(hit, "");
		sfText_setFillColor(hit, (sfColor){255, 255, 255, 255});
		sfText_setRotation(hit, 0);
		return (1);
	}
	return (0);
}

int update_text_hit(sfText *hit, int check_hit)
{
	static int new_size = 0;
	static int offset = 0;

	if ((sfText_getPosition(hit).y > 0 &&
	sfMouse_isButtonPressed(sfMouseLeft)) || check_hit == 1) {
		sfText_setString(hit, "-200");
		sfText_setOrigin(hit, (sfVector2f){80, 85});
		sfText_move(hit, (sfVector2f){0, -10});
		sfText_setFillColor(hit, (sfColor){255, 0, 0, offset});
		offset -= 10;
		if (sfText_getCharacterSize(hit) != 0)
			new_size = sfText_getCharacterSize(hit) + 1;
		else
			new_size = 0;
		sfText_setCharacterSize(hit, new_size);
		return (1);
	}
	return (0);
}

int manage_hit_enemy(my_w_t *window)
{
	scene_t *battle_game = hm_get(window->scenes, "BATTLE");
	sfText *hit = hm_get(battle_game->texts, "HIT");
	static int check_hit;

	if (!hit)
		return (0);
	if (re_init_at_initial(hit) == 1) {
		check_hit = 0;
		return (0);
	}
	if (update_text_hit(hit, check_hit) == 1)
		check_hit = 1;
	return (0);
}