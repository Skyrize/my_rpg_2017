/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

void affichage_inventaire_a_refaire(my_w_t *window)
{
	if (PLAYER_WEAPON.item.obj)
		sfRenderWindow_drawRectangleShape(window->window, PLAYER_WEAPON.item.obj->obj, NULL);
	if (PLAYER_HELMET.item.obj)
		sfRenderWindow_drawRectangleShape(window->window, PLAYER_HELMET.item.obj->obj, NULL);
	if (PLAYER_CHEST.item.obj)
		sfRenderWindow_drawRectangleShape(window->window, PLAYER_CHEST.item.obj->obj, NULL);
	if (PLAYER_GAUNTLETS.item.obj)
		sfRenderWindow_drawRectangleShape(window->window, PLAYER_GAUNTLETS.item.obj->obj, NULL);
	if (PLAYER_PANTS.item.obj)
		sfRenderWindow_drawRectangleShape(window->window, PLAYER_PANTS.item.obj->obj, NULL);
	for (int Y = 0; Y != INVENTORY_SIZE_Y; Y++) {
		for (int X = 0; X != INVENTORY_SIZE_X; X++) {
			if (PLAYER_ITEMS[Y][X].item.obj)
				sfRenderWindow_drawRectangleShape(window->window, PLAYER_ITEMS[Y][X].item.obj->obj, NULL);
		}
	}
}

int display_scenes(my_w_t *window)
{
	display_list_t *tmp = window->displayed_scenes;

	if (my_strcmp(tmp->scene_name, MAP_SCENE_NAME) == 0)
		if (display_map(window) != 0)
			return (84);
	while (tmp) {
		if (display_objs(tmp->scene->objs, window) != 0)
			return (84);
		if (read_hashmap(window, tmp->scene->texts,
			&display_texts) != 0)
			return (84);
		///to change
		if (my_strcmp(tmp->scene_name, "INVENTORY") == 0)
			affichage_inventaire_a_refaire(window);
		tmp = tmp->next;
	}
	return (0);
}
