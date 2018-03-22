/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** My world header
*/

#ifndef MAP_EDITOR
#define MAP_EDITOR

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window/Event.h>
#include "my.h"
#include "rpg.h"

typedef sfVector2f v2f;
typedef sfVector2i v2i;

typedef struct texture_list_s texture_list_t;

typedef struct texture_list_s {
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f pos;
	texture_list_t *next;
} texture_list_t;

typedef struct ressources_s {
	sfRenderWindow *window;
	my_w_t *rsces;
} ressources_t;

void on_event(ressources_t *, sfEvent);
v2i area_selector(void);
int seek_zone(my_w_t *, char *);
texture_list_t *read_hashmap_texture(hashmap_t *);
void draw_texture_list(texture_list_t *list, sfRenderWindow *);
void time_animation(obj_t *obj, float seconds, my_w_t *window);
int display_map(my_w_t *window);
int check_invalid_tile_display(tile_list_t *tile, int x, int y, my_w_t *window);

#endif /* MAP_EDITOR */
