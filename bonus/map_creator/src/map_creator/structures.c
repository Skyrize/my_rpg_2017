/*
** EPITECH PROJECT, 2017
** my_world_2017
** File description:
** structures.c created: 13/02/18 14:53
*/

#include "../../include/my_world.h"
#include <SFML/Graphics.h>

sound_t *create_sounds(ressources_t *rsces)
{
	sound_t *sounds = malloc(sizeof(sound_t));

	sounds->pop = sfMusic_createFromFile("sounds/Pop.ogg");
	rsces->sounds = sounds;
	return (sounds);
}

gui_t *create_gui(ressources_t *rsces)
{
	gui_t *gui = malloc(sizeof(gui_t));
	sfSprite *panel = sfSprite_create();
	sfSprite *edit_panel = sfSprite_create();
	sfSprite *background = sfSprite_create();

	sfSprite_setTexture(panel, rsces->textures->panel, sfTrue);
	sfSprite_setPosition(panel, V2F(1250, 50));
	sfSprite_setScale(panel, V2F(0.8, 0.8));
	sfSprite_setTexture(background, rsces->textures->background, sfTrue);
	sfSprite_setTexture(edit_panel, rsces->textures->editing_panel, true);
	sfSprite_setPosition(edit_panel, V2F(30, 50));
	sfSprite_setScale(edit_panel, V2F(0.8, 0.8));
	gui->panel = panel;
	gui->editing_panel = edit_panel;
	gui->background = background;
	gui->grid = 0;
	gui->mode = 1;
	gui->click = false;
	rsces->gui = gui;
	return (gui);
}

textures_t *create_textures(ressources_t *rsces)
{
	textures_t *texs = malloc(sizeof(textures_t));

	texs->dirt = sfTexture_createFromFile("img/dirt.png", NULL);
	texs->grass = sfTexture_createFromFile("img/grass.png", NULL);
	texs->stone = sfTexture_createFromFile("img/stone.png", NULL);
	texs->panel = sfTexture_createFromFile("img/panel.png", NULL);
	texs->editing_panel = sfTexture_createFromFile("img/editing_tool.png",
									NULL);
	texs->background = sfTexture_createFromFile("img/background.png", NULL);
	rsces->textures = texs;
	return (texs);
}

sfRenderStates *create_state(sfTexture *text)
{
	sfRenderStates *ret = malloc(sizeof(sfRenderStates));

	ret->shader = NULL;
	ret->blendMode = sfBlendNone;
	ret->transform = sfTransform_fromMatrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
	ret->texture = text;
	return (ret);
}
