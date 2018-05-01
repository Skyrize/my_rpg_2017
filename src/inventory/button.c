/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int display_item_stats(slot_t *slot, game_t *game)
{
	static char *old_scene = NULL;
	/*static sfRectangleShape *ico_item = NULL;
	static char *last_item = NULL;*/
	if (!slot|| !game || !slot->item || !slot->item->name)
		return (84);
	if (get_scene_from_displayed(STATS_GAME, game) == NULL) {
		if (my_strcmp(CURRENT_SCENE->key, "STATS"))
			old_scene = CURRENT_SCENE->key;
		if (button_display_hide_scene(STATS_GAME,
		&update_stats, game, old_scene) == 84)
			return (84);
	}
	if (update_item_info(slot, game) != 0)
		return (0);
	/*printf("debug : %d\n", my_strcmp(last_item, slot->item->name));
	if (my_strcmp(last_item, slot->item->name) != 0
	&& slot->item->obj != NULL) {
		ico_item = sfRectangleShape_create();
		sfRectangleShape_setPosition(ico_item, (sfVector2f){200, 100});
		sfRectangleShape_setTexture(ico_item,
		sfRectangleShape_getTexture(slot->item->obj->obj), sfTrue);
	}
	last_item = my_strdup(slot->item->name);*/
	return (0);
}

int select_slot(slot_t *slot, game_t *game)
{
	if (!slot->item)
		return (0);
	ITEM_SELECTED = slot->item;
	if (replace_mouse_skin(slot->item->obj, &V2F(16, 16), game) != 0)
		return (84);
	slot->item = NULL;
	return (0);
}

int drop_slot(slot_t *slot, game_t *game)
{
	item_t *tmp;

	if (!slot->item) {
		slot->item = ITEM_SELECTED;
		sfRectangleShape_setPosition(slot->item->obj->obj, slot->pos);
		ITEM_SELECTED = NULL;
		return (reset_mouse_skin(game));
	} else {
		tmp = slot->item;
		slot->item = ITEM_SELECTED;
		sfRectangleShape_setPosition(slot->item->obj->obj, slot->pos);
		ITEM_SELECTED = NULL;
		ITEM_SELECTED = tmp;
		return (replace_mouse_skin(ITEM_SELECTED->obj,
		&V2F(16, 16), game));
	}
	return (0);
}

int click_slot(slot_t *slot, game_t *game)
{
	if (!slot || !game)
		return (84);
	if (!ITEM_SELECTED) {
		return (select_slot(slot, game));
	} else {
		return (drop_slot(slot, game));
	}
	return (0);
}
