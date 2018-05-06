/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** random.c
*/

#include "rpg.h"
#include "my.h"

bucket_t **get_dialogue_hud_texts(game_t *game)
{
	scene_t *dialogue_scene = hm_get(SCENES, "DIALOGUE_HUD");
	bucket_t **texts = malloc(sizeof(bucket_t *) * 4);

	if (!dialogue_scene || !texts)
		return (NULL);
	texts[0] = hm_get_bucket(dialogue_scene->texts, "NAME");
	texts[1] = hm_get_bucket(dialogue_scene->texts, "LINE_01");
	texts[2] = hm_get_bucket(dialogue_scene->texts, "LINE_02");
	texts[3] = hm_get_bucket(dialogue_scene->texts, "LINE_03");
	if (!texts[0] || !texts[1] || !texts[2] || !texts[3])
		return (NULL);
	return (texts);
}

int update_nothing_here(game_t *game)
{
	bucket_t **texts = get_dialogue_hud_texts(game);
	char *name = my_strcat(PLAYER_NAME, " :");
	char *line_01 = "Nothing to do here ..";
	char *line_02 = "";

	if (!texts)
		return (84);
	sfText_setString(texts[0]->value, name);
	sfText_setString(texts[1]->value, line_01);
	sfText_setString(texts[2]->value, line_02);
	sfText_setString(texts[3]->value, line_02);
	free(texts);
	free(name);
	return (0);
}

int update_random_pnj_dialogue(char *named, game_t *game)
{
	bucket_t **texts = get_dialogue_hud_texts(game);
	char *name = my_strcat(named, " :");
	char *line_01 = "Hello adventurer !";
	char *line_02 = "Welcome to the village of Pikili.";
	char *line_03 = "You are free to visit. Don't forget the tavern.";

	if (!texts)
		return (84);
	sfText_setString(texts[0]->value, name);
	sfText_setString(texts[1]->value, line_01);
	sfText_setString(texts[2]->value, line_02);
	sfText_setString(texts[3]->value, line_03);
	free(texts);
	free(name);
	return (0);
}