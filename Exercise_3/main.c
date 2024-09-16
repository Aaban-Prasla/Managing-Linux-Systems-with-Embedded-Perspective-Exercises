#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random_generator.h"
#include "error_handling.h"

int main(int argc, char *argv[]) {
	int min, max, num_values;

	if (argc == 4) {
		min = validate_number(argv[1]);
		max = validate_number(argv[2]);
		num_values = validate_number(argv[3]);

		if (min == -1 || max == -1 || num_values == -1) {
			printf("Invalid input: All arguments must be positive integers.\n");
			return 1;
		}
	}
	else {
		printf("Enter the minimum value: ");
		min = validate_input();

		printf("ENter the maximum value: ");
		max = validate_input();

		printf("Enter the number of unique random values: ");
		num_values = validate_input();
	}

	if (!is_valid_range(min, max)) {
		printf("Error: Minimum value must be less than or eqaul to maximum value.\n");
		return 1;
	}
	if (!is_valid_num_values(min, max, num_values)) {
		printf("Error: Number of values requested exceeds the range of possible unique values.\n");
		return 1;
	}

	int *random_values = generate_random_values(min, max, num_values);

	printf("Generated random values: ");
	for (int i = 0; i < num_values; i++) {
		printf("%d ", random_values[i]);
	}
	printf("\n");

	free(random_values);
	return 0;
}
