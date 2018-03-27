/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int select_varyan(my_w_t *window)
{
	obj_data_t character_data = {"VARYAN", "WARRIOR_01", sfFalse,
	(sfVector2f){0, 0}};

	PLAYER_NAME = "Varyan";
	PLAYER_CHARACTER = create_obj(&character_data, window);
	if (!PLAYER_CHARACTER) {
		my_printf("WARNING: ERROR IN PLAYER INIT !\n");
		return (84);
	}
	PLAYER_GOLDS = 100;
	for (int y = 0; y != INVENTORY_SIZE_Y; y++)
		for (int x = 0; x != INVENTORY_SIZE_X; x++)
			PLAYER_ITEMS[y][x] = NULL;
	PLAYER_VITALITY = 100;
	PLAYER_ARMOR = 50;
	PLAYER_SPECIALITY_NAME = "Strenght";
	PLAYER_SPECIALITY = 50;
	return (resume(window));
}

int select_jaina(my_w_t *window)
{
	obj_data_t character_data = {"JAINA", "MAGE_01", sfFalse,
	(sfVector2f){0, 0}};

	PLAYER_NAME = "Jaina";
	PLAYER_CHARACTER = create_obj(&character_data, window);
	if (!PLAYER_CHARACTER) {
		my_printf("WARNING: ERROR IN PLAYER INIT !\n");
		return (84);
	}
	PLAYER_GOLDS = 100;
	for (int y = 0; y != INVENTORY_SIZE_Y; y++)
		for (int x = 0; x != INVENTORY_SIZE_X; x++)
			PLAYER_ITEMS[y][x] = NULL;
	PLAYER_VITALITY = 100;
	PLAYER_ARMOR = 50;
	PLAYER_SPECIALITY_NAME = "Wisdom";
	PLAYER_SPECIALITY = 50;
	return (resume(window));
}

int select_avelus(my_w_t *window)
{
	obj_data_t character_data = {"AVELUS", "HUNTER_01", sfFalse,
	(sfVector2f){0, 0}};

	PLAYER_NAME = "Avelus";
	PLAYER_CHARACTER = create_obj(&character_data, window);
	if (!PLAYER_CHARACTER) {
		my_printf("WARNING: ERROR IN PLAYER INIT !\n");
		return (84);
	}
	PLAYER_GOLDS = 100;
	for (int y = 0; y != INVENTORY_SIZE_Y; y++)
		for (int x = 0; x != INVENTORY_SIZE_X; x++)
			PLAYER_ITEMS[y][x] = NULL;
	PLAYER_VITALITY = 100;
	PLAYER_ARMOR = 50;
	PLAYER_SPECIALITY_NAME = "Agility";
	PLAYER_SPECIALITY = 50;
	return (resume(window));
}
