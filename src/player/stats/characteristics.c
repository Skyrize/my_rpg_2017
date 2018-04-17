/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

void update_characteristic(int value, char *wanted, scene_t *scene)
{
	char *space = ":   ";
	char *value_string = int_to_str(value);
	char *display = my_strcat(space, value_string);
	sfText *actual = hm_get(scene->texts, wanted);

	if (actual)
		sfText_setString(actual, display);
}

void update_characteristics(scene_t *scene, my_w_t *window)
{
	update_characteristic(PLAYER_HEALTH, "HEALTH", scene);
	update_characteristic(PLAYER_ARMOR, "ARMOR", scene);
	update_characteristic(PLAYER_SPECIALITY, "SPECIAL", scene);
}
