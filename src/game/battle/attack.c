/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** select_enemy
*/

#include "rpg.h"

int check_last_enemy(game_t *game, int i)
{
	if (i == 0) {
		if (!game->battle.enemy[1].rec && !game->battle.enemy[2].rec)
			return (1);
	} else if (i == 1) {
		if (!game->battle.enemy[2].rec)
			return (1);
	} else
		return (1);
	return (0);
}

int enemy_turn(window_t *window, game_t *game)
{
	static int i = 0;

	while (i < 2 && !game->battle.enemy[i].rec)
		i++;
	game->battle.selected_enemy = i;
	if (check_last_enemy(game, i)) {
		game->battle.last_enemy_turn = 1;
		i = -1;
		game->battle.enemy_turn = 0;
	} else
		game->battle.last_enemy_turn = 0;
	if (wait_for_enemy_attack(window, game, 1) == 84)
		return (84);
	i++;
	return (0);
}

int enemy_attack(window_t *window, game_t *game)
{
	float bonus = ((rand() % (ENEMY_DAMAGES * 2)) - ENEMY_DAMAGES) / 10;
	int damages = ENEMY_DAMAGES + round(bonus) - PLAYER_ARMOR;
	int critical_hit = rand() % 100;

	if (critical_hit >= 95) {
		damages *= 2;
		display_special_hit_enemy(window, game, "CRITICAL_HIT");
	} else if (critical_hit < 10) {
		damages = 0;
		display_special_hit_enemy(window, game, "ATTACK_FAILED");
	}
	printf("ENEMY DOES %d DAMAGES TO YOU\n", damages);
	PLAYER_HEALTH -= damages > 0 ? damages : 0;
	// if (game->battle.last_enemy_turn && !SPECIAL_HIT)
	// 	add_scene_to_display_list(hm_get_bucket(SCENES,
	// 					"BATTLE_BASIC_BUTTONS"), game);
	// else if (!SPECIAL_HIT)
	// 	enemy_turn(window, game);
	return (0);
}

int player_attack(window_t *window, game_t *game)
{
	float bonus = ((rand() % (PLAYER_DAMAGES * 2)) - PLAYER_DAMAGES) / 10;
	int damages = PLAYER_DAMAGES + round(bonus) - ENEMY_ARMOR;
	int critical_hit = rand() % 100;

	clean_displayed_scene_name(game, "ATTACK");
	if (critical_hit >= 50) {
		damages *= 2;
		display_special_hit_player(window, game, "CRITICAL_HIT");
	} else if (critical_hit < 5) {
		damages = 0;
		display_special_hit_player(window, game, "ATTACK_FAILED");
	}
	printf("YOU DO %d DAMAGES TO ENEMY\n", damages);
	ENEMY_HEALTH -= damages > 0 ? damages : 0;
	if (ENEMY_HEALTH <= 0) {
		sfRectangleShape_destroy(SELECTED_ENEMY.rec);
		SELECTED_ENEMY.rec = NULL;
	}
	return (0);
}

int attack(window_t *window, game_t *game)
{
	bucket_t *bucket = hm_get_bucket(SCENES, "ATTACK");

	if (!window || !game || !bucket)
		return (84);
	add_scene_to_display_list(bucket, game);
	game->battle.selected_enemy = first_enemy_available(game);
	change_arrow_position(game);
	clean_displayed_scene_name(game, "BATTLE_BASIC_BUTTONS");
	return (0);
}