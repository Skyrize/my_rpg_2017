/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_already_existing_obj(obj_data_t *data, hashmap_t *current_list)
{
	bucket_t *obj = hm_get_bucket(current_list, data->name);

	if (obj != NULL) {
		my_printf("WARNING: OBJ '%s' REDECLARED IN SCENE !\n",
		data->name);
		return (84);
	}
	return (0);
}
int check_already_existing_text(text_data_t *data, hashmap_t *current_list)
{
	bucket_t *obj = hm_get_bucket(current_list, data->name);

	if (obj != NULL) {
		my_printf("WARNING: TEXT '%s' REDECLARED IN SCENE !\n",
		data->name);
		return (84);
	}
	return (0);
}
