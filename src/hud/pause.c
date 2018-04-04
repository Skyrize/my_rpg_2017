/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int pause_game(my_w_t *window)
{
	int error_no = 0;
	sfRectangleShape *rec = sfRectangleShape_create();

	sfRectangleShape_setSize(rec, (sfVector2f){800, 600});
	sfRectangleShape_setFillColor(rec, (sfColor){0,0,0,128});
	window->key_player->move = 0;
	printf("%d\n", window->key_player->move);
	error_no = add_scene_to_display_list(
	hm_get_bucket(window->scenes, PAUSE_GAME), window);
	if (error_no == 84)
		return (84);
	sfRenderWindow_drawRectangleShape(window->window, rec, NULL);
	return (1);
}
