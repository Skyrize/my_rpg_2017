/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int init_tools(game_t *game)
{
	MOUSE_POS = V2I(0, 0);
	if (reset_mouse_skin(game) != 0)
		return (84);
	CLICK_RELEASED = sfTrue;
	FRAMERATE = 60;
	return (0);
}

void init_key_player(game_t *game)
{
	KEY_PLAYER.up = (sfKeyCode *)sfKeyZ;
	KEY_PLAYER.down = (sfKeyCode *)sfKeyS;
	KEY_PLAYER.left = (sfKeyCode *)sfKeyQ;
	KEY_PLAYER.right = (sfKeyCode *)sfKeyD;
	KEY_PLAYER.up_1 = (sfKeyCode *)sfKeyUp;
	KEY_PLAYER.down_1 = (sfKeyCode *)sfKeyDown;
	KEY_PLAYER.left_1 = (sfKeyCode *)sfKeyLeft;
	KEY_PLAYER.right_1 = (sfKeyCode *)sfKeyRight;
	KEY_PLAYER.move = 1;
}

int set_game_version(game_t *game)
{
	bucket_t *scene = hm_get_bucket(SCENES, PAUSE_GAME);
	bucket_t *text = NULL;
	scene_t *curr_scene = NULL;

	if (check_unexisting_scene(scene, PAUSE_GAME) != 0)
		return (84);
	curr_scene = scene->value;
	text = hm_get_bucket(curr_scene->texts, "VERSION_GAME");
	if (check_unexisting_text(text, "VERSION_GAME", scene->key) != 0)
		return (84);
	sfText_setString(text->value, VERSION_GAME);
	return (0);
}

void init_movement(game_t *game)
{
	game->movement.target_tile = (sfVector2i) {0, 0};
	game->movement.anim_mult = 1;
	game->movement.is_moving = false;
}

int init_game(game_t *game)
{
	game->displayed_scenes = NULL;
	if (init_map(game) != 0
	|| init_textures_lib(game) != 0
	|| init_audio_lib(game) != 0
	|| init_fonts_lib(game) != 0
	|| init_items_lib(game) != 0
	|| init_monsters_lib(game) != 0
	|| init_scenes(game) != 0
	|| init_inventory(game) != 0
	|| init_buttons(game) != 0
	|| init_tools(game) != 0)
		return (84);
	if (set_game_version(game) != 0)
		return (84);
	init_key_player(game);
	init_movement(game);
	init_player(game);
	return (0);
}