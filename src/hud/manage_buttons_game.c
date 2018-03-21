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

int callback_func(obj_t *button, my_w_t *window)
{
		return (button->callback(window));
	return (0);
}

int process_button_over(obj_t *button, my_w_t *window)
{
	if (button_fly_over(button, POS_MOUSE) == 1 &&
	buttonisclicked((button), POS_MOUSE) == 0)
		sfRectangleShape_setFillColor(button->obj, OVER_COLOR);
	else if (button_fly_over(button, POS_MOUSE) == 1 &&
	buttonisclicked((button), POS_MOUSE) == 1) {
		for (int i = 40000000 ; i != 0 ; i--);
		return (button->callback(window));
	} else
		sfRectangleShape_setFillColor(button->obj, REGULAR_COLOR);
	return (0);
}

int read_buttons(my_w_t *window, bucket_t *button_bucket)
{
	bucket_t *tmp = button_bucket;
	obj_t *button = button_bucket->value;

	while (tmp) {
		if (button->button == sfTrue)
			process_button_over(button, window);
		tmp = tmp->next;
	}
	return (0);
}
void read_scene_button(scene_t *scene, my_w_t *window)
{
	for (int i = 0 ; i != OBJS_TYPE_NB ; i++) {
		read_hashmap(window, scene->objs[i], &read_buttons);
	}
}

int manage_buttons(my_w_t *window)
{
	display_list_t *tmp = window->displayed_scenes;

	while (tmp) {
		read_scene_button(tmp->scene, window);
		tmp = tmp->next;
	}
	return (0);
}