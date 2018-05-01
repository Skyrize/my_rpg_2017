/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** select_enemy
*/

#include "rpg.h"

int first_enemy_available(game_t *game)
{
	if (game->battle.enemy[0]->monster->obj)
		return (0);
	if (game->battle.enemy[1]->monster->obj)
		return (1);
	return (2);
}

int change_selected_enemy(game_t *game, int offset)
{
	int selected = game->battle.selected_enemy;
	int to_select = selected + offset;

	for (int i = 0; i < 3; i++) {
		if (to_select > 2)
			to_select = 0;
		if (to_select < 0)
			to_select = 2;
		if (game->battle.enemy[to_select]->monster->obj) {
			game->battle.selected_enemy = to_select;
			return (0);
		}
		to_select += offset;
	}
	return (1);
}

void change_arrow_position(game_t *game)
{
	scene_t *scene = hm_get(SCENES, "ATTACK");
	obj_t *arrow = hm_get(scene->objs, "SELECTOR");

	sfRectangleShape_setPosition(arrow->obj,
	V2F(612 + game->battle.selected_enemy * 25,
	175 + game->battle.selected_enemy * 50));
}

void select_ennemy(window_t *window, game_t *game)
{
	if (get_scene_from_displayed("ATTACK", game)
	&& window->event.type == sfEvtKeyPressed) {
		if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
			change_selected_enemy(game, -1);
			change_arrow_position(game);
		} else if (sfKeyboard_isKeyPressed(sfKeyRight)) {
			change_selected_enemy(game, 1);
			change_arrow_position(game);
		}
		if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
			player_attack(window, game);
			// !SPECIAL_HIT ? game->battle.enemy_turn = 1,
			// enemy_turn(window, game) : 0;
			//!SPECIAL_HIT ? enemy_turn(window, game) : 0;
			//enemy_turn(window, game);
		}
	}
}