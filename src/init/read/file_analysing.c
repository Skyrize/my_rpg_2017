/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int init_from_pcf(char **infos, game_t *game, const key_word_t *keys)
{
	char **type = my_str_to_word_array(infos[0], '=');
	static hashmap_t *current_list;
	unsigned int i = 0;
	int my_errno = 0;

	for (; keys[i].key_word; i++) {
		if (my_fastcmp(keys[i].key_word, type[0]) == 0
		&& check_missing_or_invalid_sub_keyword(keys, i, infos) != 0)
			return (84);
		if (my_fastcmp(keys[i].key_word, type[0]) == 0) {
			my_errno = keys[i].fptr(infos, type,
				&current_list, game);
			break;
		}
	}
	if (check_invalid_key_word(keys[i].key_word, type, infos,
		my_errno) != 0)
		return (84);
	return (0);
}

int get_infos(int fd, game_t *game, get_infos_t *infos)
{
	char *line = my_get_next_line(fd);
	char **line_words;

	while (line && my_strlen(line) > 0) {
		line_words = my_str_to_word_array(line, DATASET_SEPARATOR_CHAR);
		if (!line_words || !line_words[0])
			return (84);
		if (init_from_pcf(line_words, game, infos->keys) != 0)
			return (84);
		free(line);
		line = my_get_next_line(fd);
	}
	return (0);
}

int analyse_pcf(game_t *game, get_infos_t *infos)
{
	int fd = open(infos->filepath, O_RDONLY);
	char *line = NULL;
	int my_errno = 0;

	if (check_invalid_file(fd, infos->filepath) != 0)
		return (84);
	line = my_get_next_line(fd);
	while (my_fastcmp(line, END_OF_FILE) == 1) {
		if (my_fastcmp(line, infos->indicator) == 0) {
			infos->savior(game);
			my_errno = get_infos(fd, game, infos);
		}
		if (my_errno != 0)
			return (my_errno);
		free(line);
		line = my_get_next_line(fd);
	}
	free(line);
	close(fd);
	return (my_errno);
}
