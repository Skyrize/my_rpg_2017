/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int init_my_player(my_w_t *window)
{
	obj_data_t character_data = {"VARYAN", "WARRIOR_01", sfFalse,
	(sfVector2f){0, 0}};

	PLAYER_NAME = "VARYAN";
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
	PLAYER_ARMOR = 4;
	PLAYER_SPECIALITY_NAME = "mokolo";
	PLAYER_SPECIALITY = 5;
	return (0);
}
