/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** load.c
*/

#include "rpg.h"

int load_player(int fd_player, player_t *player)
{
	char buffer[4096];
	int bytes = 0;

	memset(buffer, 0, 4095);
	bytes = read(fd_player, buffer, 4095);
	if (bytes == -1)
		return (84);
	my_printf("buffer = %s\n", buffer);
	player = (player_t *)buffer;
	return (0);
}

int load_save(int fd_player, int fd_npc, game_t *game)
{
	player_t player;

	if (load_player(fd_player, &player) != 0)
		return (84);
	my_printf("player_name = %s\n", player.name);
	return (0);
}