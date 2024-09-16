#include <stdio.h>
#include <stdlib.h>
#include "error_handling.h"

int validate_number(char *str) {
	char *end;
	long num = strtol(str, &end, 10);

	if (*end != '\0' || num < 0) {
		return -1;
	}
	return (int)num;
}

int validate_input() {
	char buffer[100];
	scanf("%s", buffer);
	return validate_number(buffer);
}

int is_valid_range (int min, int max) {
	return min <= max;
}

int is_valid_num_values(int min, int max, int num_values) {
	int range = max - min +1;
	return num_values <= range;
}
