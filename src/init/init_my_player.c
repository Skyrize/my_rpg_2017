/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int init_characteristics_scene(char **desc, obj_data_t *data, my_w_t *window)
{
	scene_t *scene = hm_get(window->scenes, CHARAC_GAME);
	obj_data_t special_data = {"SPECIAL_CHARAC", desc[2], sfFalse,
	(sfVector2f){316, 215}};
	sfText *name = hm_get(scene->texts, "CHARAC");
	sfText *lore = hm_get(scene->texts, "CHARAC_DESC");

	if (!scene || !name || !lore)
		return (84);
	if (add_obj_to_list(data, scene->objs, window) != 0)
		return (84);
	if (add_obj_to_list(&special_data, scene->objs, window) != 0)
		return (84);
	sfText_setString(name, desc[0]);
	sfText_setString(lore, desc[1]);
	update_characteristics(scene, window);
	return (0);
}

int select_varyan(my_w_t *window)
{
	obj_data_t charac_data = {"VARYAN", "WARRIOR_01", sfFalse,
	(sfVector2f){304, 55}};
	char *desc[3] = {"Varyan", "The Warrior", "STRENGHT_ICON"};

	PLAYER_NAME = "Varyan";
	PLAYER_CHARACTER = create_obj(&charac_data, window);
	if (!PLAYER_CHARACTER)
		return (84);
	PLAYER_GOLDS = 100;
	for (int y = 0; y != INVENTORY_SIZE_Y; y++)
		for (int x = 0; x != INVENTORY_SIZE_X; x++)
			PLAYER_ITEMS[y][x] = NULL;
	PLAYER_HEALTH = 100;
	PLAYER_CHARAC.max_health = 100;
	PLAYER_ARMOR = 50;
	PLAYER_SPECIALITY_NAME = "Strenght";
	PLAYER_SPECIALITY = 50;
	if (init_characteristics_scene(desc, &charac_data, window) != 0)
		return (84);
	return (game(window));
}

int select_jaina(my_w_t *window)
{
	obj_data_t charac_data = {"JAINA", "MAGE_01", sfFalse,
	(sfVector2f){304, 55}};
	char *desc[3] = {"Jaina", "The Mage", "WISDOM_ICON"};

	PLAYER_NAME = "Jaina";
	PLAYER_CHARACTER = create_obj(&charac_data, window);
	if (!PLAYER_CHARACTER)
		return (84);
	PLAYER_GOLDS = 100;
	for (int y = 0; y != INVENTORY_SIZE_Y; y++)
		for (int x = 0; x != INVENTORY_SIZE_X; x++)
			PLAYER_ITEMS[y][x] = NULL;
	PLAYER_HEALTH = 100;
	PLAYER_CHARAC.max_health = 100;
	PLAYER_ARMOR = 50;
	PLAYER_SPECIALITY_NAME = "Wisdom";
	PLAYER_SPECIALITY = 50;
	if (init_characteristics_scene(desc, &charac_data, window) != 0)
		return (84);
	return (game(window));
}

int select_avelus(my_w_t *window)
{
	obj_data_t charac_data = {"AVELUS", "HUNTER_01", sfFalse,
	(sfVector2f){304, 55}};
	char *desc[3] = {"Avelus", "The Hunter", "AGILITY_ICON"};

	PLAYER_NAME = "Avelus";
	PLAYER_CHARACTER = create_obj(&charac_data, window);
	if (!PLAYER_CHARACTER)
		return (84);
	PLAYER_GOLDS = 100;
	for (int y = 0; y != INVENTORY_SIZE_Y; y++)
		for (int x = 0; x != INVENTORY_SIZE_X; x++)
			PLAYER_ITEMS[y][x] = NULL;
	PLAYER_HEALTH = 100;
	PLAYER_CHARAC.max_health = 100;
	PLAYER_ARMOR = 50;
	PLAYER_SPECIALITY_NAME = "Agility";
	PLAYER_SPECIALITY = 50;
	if (init_characteristics_scene(desc, &charac_data, window) != 0)
		return (84);
	return (game(window));
}
