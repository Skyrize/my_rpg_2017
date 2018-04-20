/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int read_bucket(window_t *window, bucket_t *bucket, int (*fptr)(bucket_t *, window_t *))
{
	bucket_t *tmp = bucket;
	int error_no = 0;

	while (tmp) {
		error_no = fptr(tmp, window);
		if (error_no != 0)
			return (error_no);
		tmp = tmp->next;
	}
	return (0);
}

int read_hashmap(window_t *window, hashmap_t *hashmap, int (*fptr)(bucket_t *, window_t *))
{
	bucket_t *tmp;
	int error_no = 0;

	for (unsigned int i = 0; i != hashmap->size; i++) {
		tmp = hashmap->data[i];
		error_no = read_bucket(window, tmp, fptr);
		if (error_no != 0)
			return (error_no);
	}
	return (0);
}
