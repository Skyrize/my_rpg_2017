/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_undefined_scene(bucket_t *scene, char *asked_list)
{
	if (!scene) {
		my_printf("WARNING: YOU ASKED FOR '%s' DATA BUT SCENE ISN'T ",
		asked_list);
		my_printf("DEFINED !\n");
		return (84);
	}
	return (0);
}

int check_undefined_texture(bucket_t *texture, char *data)
{
	if (!texture) {
		my_printf("WARNING: YOU ASKED FOR '%s' ", data);
		my_printf("DATA BUT TEXTURE ISN'T DEFINED !\n");
		return (84);
	}
	return (0);
}

int check_undefined_list(hashmap_t *current_list, char *obj)
{
	if (!current_list) {
		my_printf("WARNING: YOU TRIED TO CREATE '%s' ", obj);
		my_printf("BUT YOU DIDN'T SPECIFIED A LIST !\n");
		return (84);
	}
	return (0);
}
