/*
** EPITECH PROJECT, 2017
** my_world_2017
** File description:
** draw_gui.c
*/

#include <SFML/Window/VideoMode.h>
#include "../../include/my_world.h"

void handle_toolbar_click(ressources_t *rsces, gui_t *gui)
{
	v2i pos = sfMouse_getPositionRenderWindow(rsces->window);

	if (!gui->click)
		return;
	if (pos.y > rsces->mode.height - 120 && pos.x < 450) {
		if (pos.x > 270)
			gui->mode = 2;
		else if (pos.x > 130)
			gui->mode = 1;
		else
			rsces->map->height_map = generate_zero_float_map(
				rsces->map->size);
	}
}

void draw_toolbar(ressources_t *rsces, gui_t *gui)
{
	static sfRectangleShape *rect = NULL;
	static sfTexture *toolbar_tex = NULL;

	if (!rect) {
		rect = sfRectangleShape_create();
		toolbar_tex = sfTexture_createFromFile("img/toolbar.png",
						       NULL);
		sfRectangleShape_setTexture(rect, toolbar_tex, sfFalse);
		sfRectangleShape_setPosition(rect,
					     V2F(0, rsces->mode.height - 120));
		sfRectangleShape_setSize(rect, V2F(450, 120));
	}
	sfRenderWindow_drawRectangleShape(rsces->window, rect, NULL);
	handle_toolbar_click(rsces, gui);
}

void draw_gui(ressources_t *rsces, gui_t *gui)
{
	sfRenderWindow_drawSprite(rsces->window, gui->panel, NULL);
	sfRenderWindow_drawSprite(rsces->window, gui->editing_panel, NULL);
	draw_toolbar(rsces, gui);
}

void draw_background(ressources_t *rsces, gui_t *gui)
{
	sfRenderWindow_drawSprite(rsces->window, gui->background, NULL);
}
