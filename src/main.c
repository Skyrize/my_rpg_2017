/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** my.h
*/

#include "my.h"
#include "rpg.h"

void start_scene_music(scene_t *scene)
{
	if (scene->music) {
		sfMusic_play(scene->music);
		sfMusic_setLoop(scene->music, sfTrue);
	}
}

void init_frame_rate(my_w_t *window)
{
	bucket_t *bucket_scene = hm_get_bucket(window->scenes, OPTION_GAME);
	scene_t *scene_option = NULL;
	bucket_t *text_bucket = NULL;

	if (!bucket_scene)
		return;
	scene_option = bucket_scene->value;
	if (!scene_option)
		return;
	text_bucket = hm_get_bucket(scene_option->texts, "FRAME");
	if (!text_bucket)
		return;
	window->framerate_game = 60;
	sfText_setString(text_bucket->value,
	(char *)int_to_str(window->framerate_game));
	sfRenderWindow_setFramerateLimit(window->window,
	window->framerate_game);
}

int process_pre_window(my_w_t *window)
{
	init_frame_rate(window);
	start_scene_music(window->current->value);
	if (add_scene_to_display_list(window->current, window) != 0)
		return (84);
	if (load_my_zone(window) != 0)
		return (84);
	TILE_COOR_X = 8;
	TILE_COOR_Y = 6;
	AREA_COOR_X = 0;
	AREA_COOR_Y = 2;
	ZONE_COOR_X = 0;
	ZONE_COOR_Y = 0;
	return (0);
}

int main()
{
	my_w_t window = init_my_window();

	if (check_invalid_window_init(window.error_no) != 0)
		return (84);
	if (process_pre_window(&window) != 0)
		return (84);
	while (sfRenderWindow_isOpen(window.window)) {
		get_time(&window);
		sfRenderWindow_clear(window.window, sfBlack);
		if (game_lobby(&window) != 0)
			return (84);
		sfRenderWindow_display(window.window);
	}
	destroy_and_free(&window);
	return (0);
}
