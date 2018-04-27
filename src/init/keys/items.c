/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int get_an_item(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	item_t *item = create_item(&(item_data_t){type[1], NULL, 0, 0,
	(item_stat_t){0, 0, 0, 0}});

	if (!item)
		return (84);
	*current_list = ITEMS_LIB;
	if (check_already_existing_item(*current_list, type[1]) != 0)
		return (84);
	hm_add(*current_list, type[1], item);
	CURRENT_SCENE = hm_get_bucket(*current_list, type[1]);
	(void)infos;
	return (0);
}

int get_an_item_texture(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	item_t *item;

	if (check_undefined_item(CURRENT_SCENE, type[0]) != 0)
		return (84);
	item = CURRENT_SCENE->value;
	if (!item)
		return (84);
	item->obj = create_obj(&(obj_data_t){CURRENT_SCENE->key,
	type[1], 1, V2F(-100, -100)}, game);
	if (!item->obj)
		return (84);
	item->obj->callback = &click_item;
	(void)infos;
	(void)current_list;
	return (0);
}

int is_item_for_quest(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	item_t *item;
	sfBool quest;

	if (check_undefined_item(CURRENT_SCENE, type[0]) != 0)
		return (84);
	item = CURRENT_SCENE->value;
	if (!item)
		return (84);
	quest = my_getnbr(type[1]);
	if (check_invalid_quest(quest) != 0)
		return (84);
	item->quest = quest;
	(void)infos;
	(void)current_list;
	return (0);
}

int is_item_consumable(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	item_t *item;
	sfBool consumable;

	if (check_undefined_item(CURRENT_SCENE, type[0]) != 0)
		return (84);
	item = CURRENT_SCENE->value;
	if (!item)
		return (84);
	consumable = my_getnbr(type[1]);
	if (check_invalid_consumable(consumable) != 0)
		return (84);
	item->consumable = consumable;
	(void)infos;
	(void)current_list;
	return (0);
}

int get_item_stats(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	item_t *item;
	char **hp = my_str_to_word_array(infos[1], KEYWORD_SEPARATOR_CHAR);
	char **armor = my_str_to_word_array(infos[2], KEYWORD_SEPARATOR_CHAR);
	char **special = my_str_to_word_array(infos[3], KEYWORD_SEPARATOR_CHAR);
	char **damage = my_str_to_word_array(infos[4], KEYWORD_SEPARATOR_CHAR);

	if (check_undefined_item(CURRENT_SCENE, infos[0]) != 0)
		return (84);
	item = CURRENT_SCENE->value;
	if (!hp || !armor || !special || !damage || !item)
		return (84);
	item->stats = (item_stat_t){my_getnbr(hp[1]), my_getnbr(armor[1]),
		my_getnbr(special[1]), my_getnbr(damage[1])};
	my_destroy_tab(hp);
	my_destroy_tab(armor);
	my_destroy_tab(special);
	my_destroy_tab(damage);
	(void)type;
	(void)current_list;
	return (0);
}
