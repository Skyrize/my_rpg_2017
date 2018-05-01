/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int pause_game(window_t *window, game_t *game)
{
	my_printf("C SAL\n PAUSE GAME A REFAIRE\n");
	sfRectangleShape *rec = NULL;
	static char *old_scene = NULL;
	
	if (!window || !game)
		return (84);
	if (my_strcmp(CURRENT_SCENE->key, PAUSE_GAME))
		old_scene = CURRENT_SCENE->key;
	rec = sfRectangleShape_create();
	sfRectangleShape_setSize(rec, (sfVector2f){800, 600});
	sfRectangleShape_setFillColor(rec, (sfColor){0,0,0,128});
	sfRenderWindow_drawRectangleShape(window->window, rec, NULL);
	return (button_display_hide_scene(PAUSE_GAME, NULL, game, old_scene));
}
