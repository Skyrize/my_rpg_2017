/*
** EPITECH PROJECT, 2017
** my_prg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

static const button_t g_tab[] =
{
	{(char *[]){"NEW_GAME", NULL}, new_game},
	{(char *[]){"CONTINUE", NULL}, game},
	{(char *[]){"SELECT_VARYAN", NULL}, select_varyan},
	{(char *[]){"SELECT_JAINA", NULL}, select_jaina},
	{(char *[]){"SELECT_AVELUS", NULL}, select_avelus},
	{(char *[]){"OPTION", NULL}, option},
	{(char *[]){"CREDITS", NULL}, credits},
	{(char *[]){"STATS", NULL}, stats},
	{(char *[]){"INVENTORY", NULL}, inventory},
	{(char *[]){"MAP", NULL}, map},
	{(char *[]){"PAUSE", NULL}, pause_game},
	{(char *[]){"QUESTS", NULL}, quetes},
	{(char *[]){"QUIT", NULL}, quit},
	{(char *[]){"LOAD", NULL}, reload},
	{(char *[]){"RESUME", NULL}, resume},
	{(char *[]){"SAVE", NULL}, save},
	{(char *[]){"EXIT", NULL}, exit_game},
	{(char *[]){"HOME", NULL}, main_menu},
	{(char *[]){"SONG", NULL}, manage_song},
	{(char *[]){"FRAME_RATE_MORE", NULL}, frame_rate_more},
	{(char *[]){"FRAME_RATE_LESS", NULL}, frame_rate_less},
	{(char *[]){"CONTROL", NULL}, control_key},
	{(char *[]){"KEY_ZQSD", NULL}, key_french},
	{(char *[]){"KEY_WASD", NULL}, key_english},
	{(char *[]){"YES", NULL}, yes_save},
	{(char *[]){"NO", NULL}, no_save},
	{(char *[]){"ATTACK", NULL}, exit_game},
	{(char *[]){"SLOT_HELMET", NULL}, helmet_slot},
	{(char *[]){"SLOT_CHEST", NULL}, chest_slot},
	{(char *[]){"SLOT_GAUNTLETS", NULL}, gauntlets_slot},
	{(char *[]){"SLOT_PANTS", NULL}, pants_slot},
	{(char *[]){"SLOT_WEAPON", NULL}, weapon_slot},
	{(char *[]){"SLOT_00", "SLOT_01", "SLOT_02", "SLOT_03", "SLOT_04", "SLOT_10", "SLOT_11", "SLOT_12", "SLOT_13", "SLOT_14", "SLOT_20", "SLOT_21", "SLOT_22", "SLOT_23", "SLOT_24", "SLOT_30", "SLOT_31", "SLOT_32", "SLOT_33", "SLOT_34", "SLOT_40", "SLOT_41", "SLOT_42", "SLOT_43", "SLOT_44", NULL}, slot},
	{NULL, NULL}
};

int init_button_callback(bucket_t *button_bucket, my_w_t *window);

int update_button(char *seek, char *replacement, scene_t *scene, my_w_t *window)
{
	bucket_t *button_bucket = hm_get_bucket(scene->objs, seek);
	bucket_t *text_bucket = hm_get_bucket(scene->texts, seek);
	sfText *text;

	if (!button_bucket || !text_bucket)
		return (84);
	text = text_bucket->value;
	free(button_bucket->key);
	free(text_bucket->key);
	button_bucket->key = my_strdup(replacement);
	text_bucket->key = my_strdup(replacement);
	if (!button_bucket->key || !text_bucket->key)
		return (84);
	sfText_setString(text, replacement);
	return (init_button_callback(button_bucket, window));
}

int seek_button_type(char **balise, int (*instruction)(), char *button_key, obj_t *button)
{
	int i = 0;

	for (; balise[i]; i++) {
		if (my_fastcmp(balise[i], button_key) == 0) {
			button->callback = instruction;
			break;
		}
	}
	return (0);
}

int init_button_callback(bucket_t *button_bucket, my_w_t *window)
{
	obj_t *button = button_bucket->value;
	int my_errno = 0;

	if (!button)
		return (84);
	if (button->button == sfFalse)
		return (0);
	button->callback = NULL;
	for (int i = 0; g_tab[i].balise != 0; i++) {
		my_errno = seek_button_type(g_tab[i].balise,
		g_tab[i].instruction, button_bucket->key, button);
		if (my_errno != 0)
			break;
	}
	if (!button->callback) {
		my_printf("WARNING: CAN'T FIND BUTTON '%s' !\n",
		button_bucket->key);
		return (84);
	}
	(void)window;
	return (my_errno);
}

int read_scenes(bucket_t *scene_bucket, my_w_t *window)
{
	scene_t *scene = scene_bucket->value;

	if (read_hashmap(window, scene->objs,
		&init_button_callback) != 0)
		return (84);
	return (0);
}

int init_my_buttons(my_w_t *window)
{
	if (read_hashmap(window, SCENES, &read_scenes) != 0)
		return (84);
	return (0);
}
