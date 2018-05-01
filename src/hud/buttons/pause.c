/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

sfRectangleShape *init_pause_shape(void)
{
	sfRectangleShape *rec = sfRectangleShape_create();

	if (!rec)
		return (NULL);
	sfRectangleShape_setSize(rec, (sfVector2f){800, 600});
	sfRectangleShape_setFillColor(rec, (sfColor){0, 0, 0, 128});
	return (rec);
}

int pause_game(window_t *window, game_t *game)
{
	static char *old_scene = NULL;
	static sfBool pass = sfTrue;
	static sfRectangleShape *rec = NULL;
	
	if (!window || !game || !rec)
		return (84);
	if (my_strcmp(CURRENT_BUCKET->key, PAUSE_GAME))
		old_scene = CURRENT_BUCKET->key;
	if (pass == sfTrue) {
		rec = init_pause_shape();
		pass = sfFalse;
	}
	sfRenderWindow_drawRectangleShape(window->window, rec, NULL);
	return (button_display_hide_scene(PAUSE_GAME, NULL, game, old_scene));
}
