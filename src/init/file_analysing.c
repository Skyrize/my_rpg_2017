/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int get_infos(int fd, my_w_t *window, get_infos_t *infos)
{
	char *getline = my_get_next_line(fd);
	char **line_words;

	while (getline && my_strlen(getline) > 0) {
		line_words = my_str_to_word_array(getline, ' ');
		if (!line_words)
			return (84);
		if (infos->fptr(line_words, window) != 0) {
			my_printf("WARNING: ERROR IN INITIALISATION\n");
			return (84);
		}
		free(getline);
		getline = my_get_next_line(fd);
	}
	return (0);
}

int analyse_my_project_config_file(my_w_t *window, get_infos_t *infos)
{
	int fd = open(infos->filepath, O_RDONLY);
	char *getline = NULL;
	int error_no = 0;

	if (fd == -1) {
		my_printf("WARNING: CAN'T FIND '%s' FILE !\n", infos->filepath);
		return (84);
	}
	getline = my_get_next_line(fd);
	while (my_fastcmp(getline, "### END OF FILE ###") == 1) {
		if (my_fastcmp(getline, infos->indicator) == 0)
			error_no = get_infos(fd, window, infos);
		if (error_no != 0)
			return (error_no);
		free(getline);
		getline = my_get_next_line(fd);
	}
	close(fd);
	return (error_no);
}
