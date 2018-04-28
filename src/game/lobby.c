/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** null
*/

#include "my.h"
#include "rpg.h"

void get_time(ctime_t *clocker)
{
	clocker->timer = sfClock_getElapsedTime(clocker->clock);
	clocker->seconds = clocker->timer.microseconds / 1000000.0;
}

int manage_versus_ico(game_t *game, int *check)
{
	scene_t *battle_game = NULL;
	obj_t *obj = NULL;
	static int offset = 1;
	static int check_offset = 0;
	sfRectangleShape *versus_ico = NULL;

	if (!game)
		return (84);
	if ((battle_game = hm_get(game->scenes, "BATTLE")) == NULL)
		return (84);
	if (*check != 0) {
		offset = 1;
		check_offset = 0;
		return (0);
	}
	if ((obj = hm_get(battle_game->objs, "VERSUS_ICO")) == NULL)
		return (84);
	if ((versus_ico = obj->obj) == NULL)
		return (84);
	sfRectangleShape_setFillColor(versus_ico, (sfColor){255, 255, 255 ,
	offset});
	offset >= 255 ? check_offset = 1 : 0;
	check_offset == 0 ? (offset += 2) : (offset -= 4);
	offset < 0 ? *check = 1 : 0;
	return (0);
}

int versus_animation(game_t *game, int *finished)
{
	static int animation_versus = 0;
	static int check = 0;
	scene_t *battle_game = hm_get(game->scenes, "BATTLE");
	obj_t *obj_right = NULL;
	obj_t *obj_left = NULL;
	obj_right = hm_get(battle_game->objs, "NOTIF_RIGHT");
	obj_left = hm_get(battle_game->objs, "NOTIF_LEFT");
	sfRectangleShape *notif_bg_r = obj_right->obj;
	sfRectangleShape *notif_bg_l = obj_left->obj;

	if (sfRectangleShape_getPosition(notif_bg_r).x == 780)
		check++;
	if (check < 2) {
		if (manage_versus_ico(game, &animation_versus) != 0
		|| manage_notif_right(game, "Doudou") != 0
		|| manage_notif_left(game, "Jaina") != 0)
			return (84);
	} else {
		animation_versus = 0;
		check = 0;
		*finished = 0;
		sfRectangleShape_setPosition(notif_bg_r, (sfVector2f){800, 10});
		sfRectangleShape_setPosition(notif_bg_l, (sfVector2f){-395, 10});
	}
	return (0);
}

int manage(window_t *window, game_t *game)
{
	static int anim = 0;

	if (manage_buttons(window, game) != 0) {
		my_printf("WARNING: ERROR IN BUTTONS !\n");
		return (84);
	}
	if (manage_life(game) != 0
	|| change_area_hud(game) != 0
	|| anim_player(game) != 0
	|| manage_hud_opacity(game) != 0)
		return (84);
	if (sfMouse_isButtonPressed(sfMouseLeft))
		anim = 1;
	smooth_move_player(game);
	return (0);
}

int game_lobby(window_t *window, game_t *game)
{
	analyse_events(window, game);
	MOUSE_POS = sfMouse_getPosition((const sfWindow *)window->window);
	if (display_scenes(window, game) != 0) {
		my_printf("WARNING: ERROR IN DISPLAY !\n");
		return (84);
	}
	if (manage(window, game) != 0)
		return (84);
	return (0);
}
