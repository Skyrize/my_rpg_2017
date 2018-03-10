/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

void scenes_destroy(scene_t *scene)
{
	hm_destroy(scene->texts);
	hm_destroy(scene->objs[BACKGROUNDS]);
	hm_destroy(scene->objs[PNJS]);
	hm_destroy(scene->objs[ITEMS]);
	hm_destroy(scene->objs[BUTTONS]);
}

void obj_destroy(game_objs_t *obj)
{
	sfRectangleShape_destroy(obj->obj);
}

void destroy_and_free(my_w_t *window)
{
	hm_destroy(window->textures_lib);
	hm_destroy(window->audio_lib);
	hm_destroy(window->fonts_lib);
	hm_destroy(window->scenes);
	sfClock_destroy(window->clocker.clock);
	sfRenderWindow_destroy(window->window);
}
