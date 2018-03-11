/*
** EPITECH PROJECT, 2018
** my_cook_2017
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

void process_pre_window(my_w_t *window, bucket_t **current_scene)
{
	sfRenderWindow_setFramerateLimit(window->window, 60);
	*current_scene = hm_get_bucket(window->scenes, window->actual_scene);
	(void)current_scene;
	start_scene_music((*current_scene)->value);
}

void look_if_scene_has_changed(my_w_t *window, bucket_t **current_scene)
{
	if (my_strcmp((*current_scene)->key, window->actual_scene) != 0) {
		*current_scene = hm_get_bucket(window->scenes,
			window->actual_scene);
		start_scene_music((*current_scene)->value);
	}
}

int main()
{
	my_w_t window = init_my_window();
	bucket_t *current_scene = NULL;

	if (window.error_no != 0)
		return (84);
	process_pre_window(&window, &current_scene);
	while (sfRenderWindow_isOpen(window.window)) {
		get_time(&window);
		sfRenderWindow_clear(window.window, sfBlack);
		look_if_scene_has_changed(&window, &current_scene);
		if (game_lobby(&window, current_scene) != 0)
			return (84);
		sfRenderWindow_display(window.window);
	}
	destroy_and_free(&window);
	return (0);
}
