/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

obj_data_t get_obj_data_from_infos(obj_infos_t *obj)
{
	obj_data_t data;

	data.name = obj->name[1];
	data.type = obj->type[1];
	data.position.x = (float)my_getnbr(obj->x[1]);
	data.position.y = (float)my_getnbr(obj->y[1]);
	return (data);
}

int init_an_obj(char **infos, my_w_t *window, hashmap_t *current_list)
{
	obj_infos_t obj;
	obj_data_t data;

	obj.name = my_str_to_word_array(infos[0], '=');
	obj.type = my_str_to_word_array(infos[1], '=');
	obj.x = my_str_to_word_array(infos[2], '=');
	obj.y = my_str_to_word_array(infos[3], '=');
	if (check_invalid_obj_init(&obj) != 0)
		return (84);
	data = get_obj_data_from_infos(&obj);
	if (check_already_existing_obj(&data, current_list) != 0)
		return (84);
	if (add_obj_to_list(&data, current_list, window) != 0)
		return (84);
	return (0);
}

text_data_t get_text_data_from_infos(text_infos_t *text, my_w_t *window)
{
	text_data_t data;

	data.name = text->name[1];
	data.text = text->text[1];
	replace_char(data.text, TEXT_SEPARATOR_CHAR, ' ');
	data.font = hm_get(window->fonts_lib, text->font[1]);
	data.charac_size = my_getnbr(text->charac_size[1]);
	data.position.x = (float)my_getnbr(text->x[1]);
	data.position.y = (float)my_getnbr(text->y[1]);
	return (data);
}

text_infos_t get_text_infos(char **infos)
{
	text_infos_t text;

	text.name = my_str_to_word_array(infos[0], '=');
	text.text = my_str_to_word_array(infos[1], '=');
	text.font = my_str_to_word_array(infos[2], '=');
	text.charac_size = my_str_to_word_array(infos[3], '=');
	text.x = my_str_to_word_array(infos[4], '=');
	text.y = my_str_to_word_array(infos[5], '=');
	return (text);
}

int init_a_text(char **infos, my_w_t *window, hashmap_t *current_list)
{
	text_infos_t text;
	text_data_t data;

	text = get_text_infos(infos);
	if (check_invalid_text_init(&text) != 0)
		return (84);
	data = get_text_data_from_infos(&text, window);
	if (check_already_existing_text(&data, current_list) != 0)
		return (84);
	if (check_unexisting_font(data.font, text.font[1]) != 0)
		return (84);
	if (add_text_to_list(&data, current_list) != 0)
		return (84);
	return (0);
}
