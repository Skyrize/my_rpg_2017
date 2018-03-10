/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int init_an_obj(char **infos, my_w_t *window, hashmap_t *current_list)
{
	char **obj_type;
	char **obj_x;
	char **obj_y;
	sfVector2f position;

	if (check_missing_information_for_obj(infos) != 0)
		return (84);
	obj_type = my_str_to_word_array(infos[0], '=');
	obj_x = my_str_to_word_array(infos[1], '=');
	obj_y = my_str_to_word_array(infos[2], '=');
	if (check_invalid_obj_init(obj_type, obj_x, obj_y) != 0)
		return (84);
	position.x = (float)my_getnbr(obj_x[1]);
	position.y = (float)my_getnbr(obj_y[1]);
	if (add_obj_to_list(obj_type[1], current_list, &position, window) != 0)
		return (84);
	return (0);
}

int init_a_text(char **infos, my_w_t *window, hashmap_t *current_list)
{
	text_infos_t text;

	if (check_missing_information_for_text(infos) != 0)
		return (84);
	text.text = my_str_to_word_array(infos[0], '=');
	text.text_font = my_str_to_word_array(infos[1], '=');
	text.text_charac_size = my_str_to_word_array(infos[2], '=');
	text.text_x = my_str_to_word_array(infos[3], '=');
	text.text_y = my_str_to_word_array(infos[4], '=');
	if (WRONG_TEXT_INIT) {
		my_printf("WARNING: INVALID TEXT INIT FORMAT");
		return (84);
	}
	if (add_text_to_list(&text, window, current_list) != 0)
		return (84);
	return (0);
}
