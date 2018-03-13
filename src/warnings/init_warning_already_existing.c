/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_already_existing_obj(obj_data_t *data, hashmap_t *current_list)
{
	bucket_t *obj = hm_get_bucket(current_list, data->name);

	if (obj != NULL) {
		my_printf("WARNING: OBJ '%s' REDECLARED IN SCENE !\n",
		data->name);
		return (84);
	}
	return (0);
}
int check_already_existing_text(text_data_t *data, hashmap_t *current_list)
{
	bucket_t *obj = hm_get_bucket(current_list, data->name);

	if (obj != NULL) {
		my_printf("WARNING: TEXT '%s' REDECLARED IN SCENE !\n",
		data->name);
		return (84);
	}
	return (0);
}

int check_already_existing_texture(hashmap_t *hashmap, char *texture_name)
{
	sfTexture *texture = hm_get(hashmap, texture_name);

	if (texture != NULL) {
		my_printf("WARNING: TEXTURE '%s' REDECLARED IN TEXTURES! \n",
		texture_name);
		return (84);
	}
	return (0);
}

int check_already_existing_audio(hashmap_t *hashmap, char *audio_name)
{
	sfMusic *audio = hm_get(hashmap, audio_name);

	if (audio != NULL) {
		my_printf("WARNING: AUDIO '%s' REDECLARED IN SOUNDS! \n",
		audio_name);
		return (84);
	}
	return (0);
}

int check_already_existing_font(hashmap_t *hashmap, char *font_name)
{
	sfFont *font = hm_get(hashmap, font_name);

	if (font != NULL) {
		my_printf("WARNING: FONT '%s' REDECLARED IN FONTS! \n",
		font_name);
		return (84);
	}
	return (0);
}
