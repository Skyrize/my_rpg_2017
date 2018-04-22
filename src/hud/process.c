/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "my.h"
#include "rpg.h"

sfVector2f vec2u_to_vec2f(sfVector2u vecu)
{
	sfVector2f vecf;

	vecf.x = (float)vecu.x;
	vecf.y = (float)vecu.y;
	return (vecf);
}

int buttonisclicked(obj_t *button, sfVector2i clickPosition)
{
	return (clickPosition.x <
	sfRectangleShape_getPosition(button->obj).x +
	sfRectangleShape_getSize(button->obj).x &&
	clickPosition.x > sfRectangleShape_getPosition(button->obj).x &&
	clickPosition.y < sfRectangleShape_getPosition(button->obj).y +
	sfRectangleShape_getSize(button->obj).y &&
	clickPosition.y > sfRectangleShape_getPosition(button->obj).y
	&& sfMouse_isButtonPressed(sfMouseLeft));

}

int button_fly_over(obj_t *button, sfVector2i clickPosition)
{
	return (clickPosition.x < sfRectangleShape_getPosition(button->obj).x +
	sfRectangleShape_getSize(button->obj).x &&
	clickPosition.x > sfRectangleShape_getPosition(button->obj).x &&
	clickPosition.y < sfRectangleShape_getPosition(button->obj).y +
	sfRectangleShape_getSize(button->obj).y &&
	clickPosition.y > sfRectangleShape_getPosition(button->obj).y);
}

int process_button_over(bucket_t *button_bucket, window_t *window, game_t *game)
{
	obj_t *button = button_bucket->value;

	if (button->button != sfTrue)
		return (0);
	if (button_fly_over(button, MOUSE_POS) == 1 &&
	buttonisclicked((button), MOUSE_POS) == 0)
		sfRectangleShape_setFillColor(button->obj, OVER_COLOR);
	else if (button_fly_over(button, MOUSE_POS) == 1 &&
	buttonisclicked((button), MOUSE_POS) == 1
	&& CLICK_RELEASED == sfTrue) {
		CLICK_RELEASED = sfFalse;
		return (button->callback ? button->callback(window, game) : 84);
	} else if (!game->movement.is_moving
	&& sfRectangleShape_getFillColor(button->obj).a == 255)
		sfRectangleShape_setFillColor(button->obj, REGULAR_COLOR);
	return (0);
}

int manage_buttons(window_t *window, game_t *game)
{
	display_list_t *tmp = DISPLAYED_SCENES;
	scene_t *scene;
	int my_errno = 0;

	while (tmp) {
		scene = tmp->scene;
		my_errno = read_hashmap(window, game, scene->objs,
			&process_button_over);
		if (my_errno == 1)
			return (0);
		if (my_errno == 84)
			return (84);
		tmp = tmp->next;
	}
	return (0);
}
