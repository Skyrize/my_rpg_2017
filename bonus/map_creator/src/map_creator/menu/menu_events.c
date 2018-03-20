/*
** EPITECH PROJECT, 2017
** my_world_2017
** File description:
** menu_loop.c
*/

#include "../../../include/my_world.h"

int menu_events(ressources_t *rsces)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(rsces->window, &event)) {
		if (event.type == sfEvtClosed) {
			sfRenderWindow_close(rsces->window);
			return (84);
		}
	}
	return (0);
}

int button_is_clicked(menu_t *button, v2i clickPosition)
{
	v2f pos = sfRectangleShape_getPosition(button->rec);
	v2f size = sfRectangleShape_getSize(button->rec);

	pos.x -= size.x / 2;
	pos.y -= size.y / 2;
	return (clickPosition.x < pos.x + size.x &&
	clickPosition.x > pos.x && clickPosition.y < pos.y + size.y &&
	clickPosition.y > pos.y);
}

int check_timer(sfClock *my_clock)
{
	static sfTime timer;
	static float counter;

	timer = sfClock_getElapsedTime(my_clock);
	counter = timer.microseconds / 1000000.;
	if (counter > 0.3) {
		sfClock_restart(my_clock);
		return (1);
	}
	return (0);
}

int check_mouse(menu_t *objects, ressources_t *rsces, sfClock *my_clock)
{
	sfVector2i pos = sfMouse_getPositionRenderWindow(rsces->window);

	if (button_is_clicked(objects, pos) == 1 && objects->state == 0) {
		sfRectangleShape_setScale(objects->rec, V2F(1.2, 1.2));
		objects->state = 1;
	} else if (button_is_clicked(objects, pos) == 0
	&& objects->state == 1) {
		sfRectangleShape_setScale(objects->rec, V2F(1, 1));
		objects->state = 0;
	}
	if (objects->state == 1 && button_is_clicked(objects, pos) == 1
	&& sfMouse_isButtonPressed(sfMouseLeft) && check_timer(my_clock) == 1) {
		sfRectangleShape_setScale(objects->rec, V2F(1, 1));
		objects->state = 1;
		return (1);
	}
	return (0);
}
