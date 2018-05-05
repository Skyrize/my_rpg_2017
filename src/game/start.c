/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** start functions
*/

#include "my.h"
#include "rpg.h"

int start_scene_music(scene_t *scene)
{
	if (!scene)
		return (84);
	if (scene->music.music && scene->music.play_music == sfTrue) {
		sfMusic_play(scene->music.music);
		sfMusic_setLoop(scene->music.music, scene->music.loop);
	}
	return (0);
}

int init_frame_rate(window_t *window, game_t *game)
{
	bucket_t *bucket_scene = hm_get_bucket(SCENES, OPTION_GAME);
	scene_t *scene_option = NULL;
	bucket_t *text_bucket = NULL;

	if (!bucket_scene)
		return (84);
	scene_option = bucket_scene->value;
	if (!scene_option)
		return (84);
	text_bucket = hm_get_bucket(scene_option->texts, "FRAME");
	if (!text_bucket)
		return (84);
	sfText_setString(text_bucket->value, int_to_str(FRAMERATE));
	sfRenderWindow_setFramerateLimit(window->window, FRAMERATE);
	sfRenderWindow_setKeyRepeatEnabled(window->window, sfTrue);
	return (0);
}

void place_player(game_t *game)
{
	ZONE_COOR_X = 3;
	ZONE_COOR_Y = 4;
	AREA_COOR_X = 0;
	AREA_COOR_Y = 0;
	TILE_COOR_X = 6;
	TILE_COOR_Y = 4;
}

int start_game(window_t *window, game_t *game)
{
	CURRENT_BUCKET = hm_get_bucket(SCENES, STARTING_SCENE_NAME);
	if (check_undefined_scene(CURRENT_BUCKET, STARTING_SCENE_NAME) != 0)
		return (84);
	if (init_frame_rate(window, game) != 0)
		return (84);
	if (start_scene_music(CURRENT_BUCKET->value) != 0)
		return (84);
	if (add_scene_to_display_list(CURRENT_BUCKET, game) != 0)
		return (84);
	place_player(game);
	if (load_my_zone(game) != 0)
		return (84);
	sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
	return (0);
}