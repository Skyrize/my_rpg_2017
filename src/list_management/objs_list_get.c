/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int read_bucket(my_w_t *window, bucket_t *bucket, int (*fptr)())
{
	bucket_t *tmp = bucket;

	while (tmp) {
		if (fptr(tmp, window) != 0)
			return (84);
		tmp = tmp->next;
	}
	return (0);
}

int read_hashmap(my_w_t *window, hashmap_t *hashmap, int (*fptr)())
{
	bucket_t *tmp;

	for (unsigned int i = 0; i != hashmap->size; i++) {
		tmp = hashmap->data[i];
		if (read_bucket(window, tmp, fptr) != 0)
			return (84);
	}
	return (0);
}
