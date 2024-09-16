#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random_generator.h"

int* generate_random_values(int min, int max, int num_values) {
	int range = max - min +1;
	int *random_values = (int*) malloc(num_values * sizeof(int));
	int *is_picked = (int*) calloc(range, sizeof(int));

	srand(time(NULL));

	for(int i = 0; i < num_values; ) {
		int rand_val = rand() % range + min;
		if (!is_picked[rand_val - min]) {
			random_values[i] = rand_val;
			is_picked [rand_val - min] = 1;
			i++;
		}

	}

	free(is_picked);
	return random_values;
}
