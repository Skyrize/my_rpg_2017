/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int init_from_pcf(char **infos, my_w_t *window, const key_word_t *keys)
{
	char **type = my_str_to_word_array(infos[0], '=');
	static hashmap_t *current_list;
	unsigned int i = 0;

	for (; keys[i].key_word; i++) {
		if (my_fastcmp(keys[i].key_word, type[0]) == 0
		&& check_missing_or_invalid_sub_keyword(keys, i, infos) != 0)
			return (84);
		if (my_fastcmp(keys[i].key_word, type[0]) == 0) {
			window->error_no = keys[i].fptr(infos, type,
				&current_list, window);
			break;
		}
	}
	if (check_invalid_key_word(keys[i].key_word, type, infos,
		window->error_no) != 0)
		return (84);
	return (0);
}

void map_savior(my_w_t *window)
{
	ZONE_COOR_X = -1;
	ZONE_COOR_Y = -1;
	AREA_COOR_X = -1;
	AREA_COOR_Y = -1;
	TILE_COOR_X = -1;
	TILE_COOR_Y = -1;
}

void list_savior(my_w_t *window)
{
	window->current = NULL;
}

int get_infos(int fd, my_w_t *window, get_infos_t *infos)
{
	char *line = my_get_next_line(fd);
	char **line_words;

	while (line && my_strlen(line) > 0) {
		line_words = my_str_to_word_array(line, DATASET_SEPARATOR_CHAR);
		if (!line_words || !line_words[0])
			return (84);
		if (init_from_pcf(line_words, window, infos->keys) != 0)
			return (84);
		free(line);
		line = my_get_next_line(fd);
	}
	return (0);
}

int analyse_my_project_config_file(my_w_t *window, get_infos_t *infos)
{
	int fd = open(infos->filepath, O_RDONLY);
	char *line = NULL;
	int error_no = 0;

	if (check_invalid_file(fd, infos->filepath) != 0)
		return (84);
	line = my_get_next_line(fd);
	while (my_fastcmp(line, END_OF_FILE) == 1) {
		if (my_fastcmp(line, infos->indicator) == 0) {
			infos->savior(window);
			error_no = get_infos(fd, window, infos);
		}
		if (error_no != 0)
			return (error_no);
		free(line);
		line = my_get_next_line(fd);
	}
	free(line);
	close(fd);
	return (error_no);
}
