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

int process_button_over(bucket_t *button_bucket, my_w_t *window)
{
	obj_t *button = button_bucket->value;

	if (button->button != sfTrue)
		return (0);
	if (button_fly_over(button, MOUSE_POS) == 1 &&
	buttonisclicked((button), MOUSE_POS) == 0)
		sfRectangleShape_setFillColor(button->obj, OVER_COLOR);
	else if (button_fly_over(button, MOUSE_POS) == 1 &&
	buttonisclicked((button), MOUSE_POS) == 1
	&& window->click_released == sfTrue) {
		window->click_released = sfFalse;
		return (button->callback != NULL ? button->callback(window) : 0);
	} else
		sfRectangleShape_setFillColor(button->obj, REGULAR_COLOR);
	return (0);
}

int manage_buttons(my_w_t *window)
{
	display_list_t *tmp = window->displayed_scenes;
	scene_t *scene;
	int error_no = 0;

	while (tmp) {
		scene = tmp->scene;
		error_no = read_hashmap(window, scene->objs,
			&process_button_over);
		if (error_no == 1)
			return (0);
		if (error_no == 84)
			return (84);
		tmp = tmp->next;
	}
	return (0);
}
