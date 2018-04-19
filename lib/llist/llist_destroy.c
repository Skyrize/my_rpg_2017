/*
** EPITECH PROJECT, 2017
** linked_list_lib
** File description:
** my_llist_create.c
*/

#include "../../include/my.h"
#include "../../include/llist.h"

void destroy_node(node_t *node)
{
	if (node) {
		free(node->key);
		free(node);
	}
}