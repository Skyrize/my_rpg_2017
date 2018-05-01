/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int init_audio_lib(game_t *game)
{
	const key_word_t audio_keys[] = {
	{"AUDIO", 1, &get_an_audio, (char *[]) {"FILEPATH", NULL}},
	{NULL, 0, NULL, NULL}};
	get_infos_t infos = {"pcf/sounds.pcf", INIT_INDICATOR, audio_keys,
	&list_savior};

	AUDIO_LIB = hm_create(64, &sfMusic_destroy);
	if (!AUDIO_LIB || analyse_pcf(game, &infos) != 0) {
		my_printf("WARNING: ERROR IN AUDIO LIB INIT !\n");
		return (84);
	}
	return (0);
}

int init_fonts_lib(game_t *game)
{
	const key_word_t font_keys[] = {
	{"FONT", 1, &get_a_font, (char *[]) {"FILEPATH", NULL}},
	{NULL, 0, NULL, NULL}};
	get_infos_t infos = {"pcf/fonts.pcf", INIT_INDICATOR, font_keys,
	&list_savior};

	FONTS_LIB = hm_create(16, &sfFont_destroy);
	if (!FONTS_LIB || analyse_pcf(game, &infos) != 0) {
		my_printf("WARNING: ERROR IN FONTS LIB INIT !\n");
		return (84);
	}
	return (0);
}

int init_items_lib(game_t *game)
{
	const key_word_t items_keys[] = {
	{"ITEM", 0, &get_an_item, NULL},
	{"TEXTURE", 0, &get_an_item_texture, NULL},
	{"QUEST", 0, &is_item_for_quest, NULL},
	{"CONSUMABLE", 0, &is_item_consumable, NULL},
	{"STATS", 4, &get_item_stats, (char *[])
	{"HEALTH", "ARMOR", "SPECIAL", "DAMAGE", NULL}},
	{NULL, 0, NULL, NULL}};
	get_infos_t infos = {"pcf/items.pcf", INIT_INDICATOR, items_keys,
	&list_savior};

	ITEMS_LIB = hm_create(512, &item_destroy);
	if (!ITEMS_LIB || analyse_pcf(game, &infos) != 0) {
		my_printf("WARNING: ERROR IN ITEMS LIB INIT !\n");
		return (84);
	}
	return (0);
}
int init_textures_lib(game_t *game)
{
	const key_word_t texture_keys[] = {
	{"TEXTURE", 0, &get_a_texture, NULL}, {"FILEPATH", 0,
	&get_a_texture_filepath, NULL},	{"PRIORITY", 0, &get_a_priority, NULL},
	{"ANIMATED", 0, &is_texture_animated, NULL}, {"RECT_VALUES", 4,
	&get_a_rect_values, (char *[]) {"LEFT", "TOP", "WIDTH", "HEIGHT",
	NULL}}, {"RECT_START", 2, &get_a_rect_start_values, (char *[]) {"X",
	"Y", NULL}}, {"RECT_MAX", 2, &get_a_rect_max_values,
	(char *[]) {"X", "Y", NULL}}, {"RECT_OFFSET", 2,
	&get_a_rect_max_offset, (char *[]) {"X", "Y", NULL}},
	{NULL, 0, NULL, NULL}};
	get_infos_t infos = {"pcf/textures.pcf", INIT_INDICATOR, texture_keys,
	&list_savior};

	TEXTURES_LIB = hm_create(512, &texture_destroy);
	if (!TEXTURES_LIB || analyse_pcf(game, &infos) != 0) {
		my_printf("WARNING: ERROR IN TEXTURES LIB INIT !\n");
		return (84);
	}
	return (0);
}
