/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

void scenes_destroy(scene_t *scene)
{
	hm_destroy(scene->texts);
	hm_destroy(scene->objs);
	free(scene);
}

void obj_destroy(obj_t *obj)
{
	sfRectangleShape_destroy(obj->obj);
}

void texture_destroy(texture_t *texture)
{
	sfTexture_destroy(texture->texture);
}

void item_destroy(item_t *item)
{
	obj_destroy(item->obj);
}

void destroy_and_free(window_t *window, game_t *game)
{
	clean_displayed_scenes(game);
	hm_destroy(TEXTURES_LIB);
	hm_destroy(AUDIO_LIB);
	hm_destroy(FONTS_LIB);
	hm_destroy(SCENES);
	sfClock_destroy(window->clocker.clock);
	sfRenderWindow_destroy(window->window);
}
