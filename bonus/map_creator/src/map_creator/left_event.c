/*
** EPITECH PROJECT, 2018
** Sans titre(Espace de travail)
** File description:
** left_event
*/

#include "map_editor.h"

int button_is_clicked(sfRectangleShape *rec, v2i clickPosition)
{
	v2f pos = sfRectangleShape_getPosition(rec);
	v2f size = sfRectangleShape_getSize(rec);

	pos.x -= size.x / 2;
	pos.y -= size.y / 2;
	return (clickPosition.x < pos.x + size.x &&
	clickPosition.x > pos.x && clickPosition.y < pos.y + size.y &&
	clickPosition.y > pos.y);
}

void check_position_in_map(ressources_t *rsces, tile_t **tiles)
{
	v2i pos = sfMouse_getPositionRenderWindow(rsces->window);

	if (!tiles)
		my_printf("LOL\n");
	for (int i = 0; i < TILE_TAB_Y; i++) {
		for (int j = 0; j < TILE_TAB_X; j++) {
			button_is_clicked(tiles[i][j].displayed_tiles->tile->obj, \
			pos) ? add_tile_to_list(rsces->selected_texture_name, \
			rsces->rsces) : 0;
			return;
		}
	}
}

void check_position_in_texture_list(ressources_t *rsces, texture_list_t *list)
{
	v2i pos = sfMouse_getPositionRenderWindow(rsces->window);

	while (list) {
		if (button_is_clicked((sfRectangleShape *)list->sprite, pos)) {
			rsces->selected = list->texture;
			rsces->selected_texture_name = list->name;
			return;
		}
		list = list->next;
	}
}

void left_click_event(ressources_t *rsces, texture_list_t *list)
{
	check_position_in_map(rsces, \
		rsces->rsces->map.areas[rsces->rsces->map.area_coord.y] \
		[rsces->rsces->map.area_coord.x].tiles);
	check_position_in_texture_list(rsces, list);
	return;
}