/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int add_character_to_scene(char *texture_spe, obj_data_t *data, my_w_t *window)
{
	scene_t *scene = hm_get(window->scenes, "CHARACTERISTICS");
	obj_data_t special_data = {"SPECIAL_CHARAC", texture_spe, sfFalse,
	(sfVector2f){316, 215}};

	if (!scene)
		return (84);
	if (add_obj_to_list(data, scene->objs, window) != 0)
		return (84);
	if (add_obj_to_list(&special_data, scene->objs, window) != 0)
		return (84);
	return (0);
}

int select_varyan(my_w_t *window)
{
	obj_data_t charac_data = {"VARYAN", "WARRIOR_01", sfFalse,
	(sfVector2f){304, 55}};

	PLAYER_NAME = "Varyan";
	PLAYER_CHARACTER = create_obj(&charac_data, window);
	if (!PLAYER_CHARACTER)
		return (84);
	PLAYER_GOLDS = 100;
	for (int y = 0; y != INVENTORY_SIZE_Y; y++)
		for (int x = 0; x != INVENTORY_SIZE_X; x++)
			PLAYER_ITEMS[y][x] = NULL;
	PLAYER_VITALITY = 100;
	PLAYER_ARMOR = 50;
	PLAYER_SPECIALITY_NAME = "Strenght";
	PLAYER_SPECIALITY = 50;
	if (add_character_to_scene("STRENGHT_ICON", &charac_data, window) != 0)
		return (84);
	return (game(window));
}

int select_jaina(my_w_t *window)
{
	obj_data_t charac_data = {"JAINA", "MAGE_01", sfFalse,
	(sfVector2f){304, 55}};

	PLAYER_NAME = "Jaina";
	PLAYER_CHARACTER = create_obj(&charac_data, window);
	if (!PLAYER_CHARACTER)
		return (84);
	PLAYER_GOLDS = 100;
	for (int y = 0; y != INVENTORY_SIZE_Y; y++)
		for (int x = 0; x != INVENTORY_SIZE_X; x++)
			PLAYER_ITEMS[y][x] = NULL;
	PLAYER_VITALITY = 100;
	PLAYER_ARMOR = 50;
	PLAYER_SPECIALITY_NAME = "Wisdom";
	PLAYER_SPECIALITY = 50;
	if (add_character_to_scene("WISDOM_ICON", &charac_data, window) != 0)
		return (84);
	return (game(window));
}

int select_avelus(my_w_t *window)
{
	obj_data_t charac_data = {"AVELUS", "HUNTER_01", sfFalse,
	(sfVector2f){304, 55}};

	PLAYER_NAME = "Avelus";
	PLAYER_CHARACTER = create_obj(&charac_data, window);
	if (!PLAYER_CHARACTER)
		return (84);
	PLAYER_GOLDS = 100;
	for (int y = 0; y != INVENTORY_SIZE_Y; y++)
		for (int x = 0; x != INVENTORY_SIZE_X; x++)
			PLAYER_ITEMS[y][x] = NULL;
	PLAYER_VITALITY = 100;
	PLAYER_ARMOR = 50;
	PLAYER_SPECIALITY_NAME = "Agility";
	PLAYER_SPECIALITY = 50;
	if (add_character_to_scene("AGILITY_ICON", &charac_data, window) != 0)
		return (84);
	return (game(window));
}
