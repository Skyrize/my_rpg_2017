/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** end_screen
*/

#include "rpg.h"

int update_type_rarity(game_t *game, scene_t *scene, char *item)
{
	char *type = get_item_type(item);
	char *rarity = get_item_rarity(item);
	sfText *txt_type = hm_get(scene, "TYPE");
	sfText *txt_rarity = hm_get(scene, "RARITY");

	if (!txt_type || !txt_rarity)
		return (84);
	sfText_setString(txt_type, type);
	sfText_setString(txt_rarity, rarity);
	return (0);
}

int compute_xp_won(game_t *game)
{
	int bonus = 3;
	int xp = 0;
	int bonus_sup = (rand() % 20) - 9;

	if (!my_strcmp(ZONE_NAME, "MORIA"))
		bonus = 1;
	else if (!my_strcmp(ZONE_NAME, "CURSED_FOREST"))
		bonus = 2;
	xp = (NBR_ENEMIES * 25 * bonus) + bonus_sup;
	PLAYER_XP += xp;
	return (xp);
}

int compute_gold_won(game_t *game)
{
	int bonus = 3;
	int gold = 0;
	int bonus_sup = (rand() % 20) - 9;

	if (!my_strcmp(ZONE_NAME, "MORIA"))
		bonus = 1;
	else if (!my_strcmp(ZONE_NAME, "CURSED_FOREST"))
		bonus = 2;
	gold = (NBR_ENEMIES * 10 * bonus) + bonus_sup;
	GOLDS += gold;
	return (gold);
}

int update_battle_result(game_t *game)
{
	scene_t *end_screen = hm_get(SCENES, "BATTLE_END_SCREEN");
	sfText *xp = hm_get(end_screen->texts, "XP");
	sfText *found = hm_get(end_screen->texts, "FOUND");
	obj_t *item_icon = hm_get(end_screen->objs, "ITEM");
	char *item = compute_loot(game);

	if (!xp || !found || !item_icon)
		return (84);
	sfText_setString(xp, my_strcat(":   ",
	int_to_str(compute_xp_won(game))));
	if (item) {
		sfText_setString(found, "YOU GOT AN ITEM!");
		sfRectangleShape_setTexture(item_icon->obj,
		hm_get(ITEMS_LIB, item), sfTrue);
		if (update_type_rarity(game, end_screen, item) == 84)
			return (84);
	}
	return (0);
}

int battle_end_screen(game_t *game, char *result)
{
	scene_t *end_screen = hm_get(SCENES, "BATTLE_END_SCREEN");
	sfText *res = NULL;

	if (!game || !end_screen)
		return (84);
	res = hm_get(end_screen->texts, "RESULT");
	if (!res)
		return (84);
	if (!my_strcmp(result, "WIN")) {
		sfText_setString(res, "YOU  WIN !");
		if (update_battle_result(game) == 84)
			return (84);
	} else {
		sfText_setString(res, "YOU  LOSE !");
		PLAYER_HEALTH = 0;
	}
	clean_displayed_scene_name(game, "BATTLE");
	add_scene_to_display_list(hm_get_bucket(SCENES,
						"BATTLE_END_SCREEN"), game);
	return (0);
}