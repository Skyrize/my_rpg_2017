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

#define V2F(x, y) (sfVector2f) {(float) x, (float) y}
#define V2I(x, y) (sfVector2i) {(int) x, (int) y}

typedef struct ressources_s {
	sfRenderWindow *window;
	my_w_t *rsces;
} ressources_t;

void on_event(ressources_t *, sfEvent);
v2i area_selector(void);

#endif /* MAP_EDITOR */
