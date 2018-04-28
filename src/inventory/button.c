/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int update_name_item(slot_t *slot, game_t *game)
{
	scene_t *stats_scene = hm_get(game->scenes, "STATS");
	bucket_t *bucket_texts = NULL;

	if (!stats_scene || !stats_scene->objs || !stats_scene->texts
	|| !slot->item || !slot->item->name)
		return (84);
	if (!(bucket_texts = hm_get_bucket(stats_scene->texts, "NAME_ITEM")))
		return (84);
	sfText_setString(bucket_texts->value, slot->item->name);
	return (0);
}

int update_quest_item(slot_t *slot, game_t *game)
{
	// scene_t *stats_scene = hm_get(game->scenes, "STATS");
	// bucket_t *bucket_texts = NULL;

	// if (!stats_scene || !stats_scene->objs || !stats_scene->texts
	// || !slot->item || !slot->item->name)
	// 	return (84);
	// if (!(bucket_texts = hm_get_bucket(stats_scene->texts, "NAME_ITEM")))
	// 	return (84);
	// sfText_setString(bucket_texts->value, slot->item->name);
	return (0);
}
int umdate_consumable_item(slot_t *slot, game_t *game)
{
	// scene_t *stats_scene = hm_get(game->scenes, "STATS");
	// bucket_t *bucket_texts = NULL;

	// if (!stats_scene || !stats_scene->objs || !stats_scene->texts
	// || !slot->item || !slot->item->name)
	// 	return (84);
	// if (!(bucket_texts = hm_get_bucket(stats_scene->texts, "NAME_ITEM")))
	// 	return (84);
	// sfText_setString(bucket_texts->value, slot->item->name);
	return (0);
}
int update_health_item(slot_t *slot, game_t *game)
{
	// scene_t *stats_scene = hm_get(game->scenes, "STATS");
	// bucket_t *bucket_texts = NULL;

	// if (!stats_scene || !stats_scene->objs || !stats_scene->texts
	// || !slot->item || !slot->item->name)
	// 	return (84);
	// if (!(bucket_texts = hm_get_bucket(stats_scene->texts, "NAME_ITEM")))
	// 	return (84);
	// sfText_setString(bucket_texts->value, slot->item->name);
	return (0);
}

int update_armor_item(slot_t *slot, game_t *game)
{
	// scene_t *stats_scene = hm_get(game->scenes, "STATS");
	// bucket_t *bucket_texts = NULL;

	// if (!stats_scene || !stats_scene->objs || !stats_scene->texts
	// || !slot->item || !slot->item->name)
	// 	return (84);
	// if (!(bucket_texts = hm_get_bucket(stats_scene->texts, "NAME_ITEM")))
	// 	return (84);
	// sfText_setString(bucket_texts->value, slot->item->name);
	return (0);
}

int update_special_item(slot_t *slot, game_t *game)
{
	// scene_t *stats_scene = hm_get(game->scenes, "STATS");
	// bucket_t *bucket_texts = NULL;

	// if (!stats_scene || !stats_scene->objs || !stats_scene->texts
	// || !slot->item || !slot->item->name)
	// 	return (84);
	// if (!(bucket_texts = hm_get_bucket(stats_scene->texts, "NAME_ITEM")))
	// 	return (84);
	// sfText_setString(bucket_texts->value, slot->item->name);
	return (0);
}

int update_damages_item(slot_t *slot, game_t *game)
{
	// scene_t *stats_scene = hm_get(game->scenes, "STATS");
	// bucket_t *bucket_texts = NULL;

	// if (!stats_scene || !stats_scene->objs || !stats_scene->texts
	// || !slot->item || !slot->item->name)
	// 	return (84);
	// if (!(bucket_texts = hm_get_bucket(stats_scene->texts, "NAME_ITEM")))
	// 	return (84);
	// sfText_setString(bucket_texts->value, slot->item->name);
	return (0);
}

int update_item_info(slot_t *slot, game_t *game)
{
	if (update_name_item(slot, game) != 0
	|| update_quest_item(slot, game) != 0
	|| umdate_consumable_item(slot, game) != 0
	|| update_health_item(slot, game) != 0
	|| update_armor_item(slot, game) != 0
	|| update_special_item(slot, game) != 0
	|| update_damages_item(slot, game) != 0)
		return (84);
}

int display_item_stats(slot_t *slot, game_t *game)
{
	if (!slot|| !game)
		return (84);
	if (get_scene_from_displayed(STATS_GAME, game) == NULL)
		if (button_display_hide_scene(STATS_GAME,
		&update_stats, game)!= 0)
			return (84);
	if (update_item_info(slot, game) != 0)
		return (0);
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
