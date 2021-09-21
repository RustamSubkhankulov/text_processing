///@file colored_output.c source file contains code for functions declarated in colored_output.h

#include <stdio.h>
#include <assert.h>

#include "colored_output.h"

void print_color(const char* color, const char* string) {

	assert(color != NULL);
	assert(string != NULL);

	printf("%s", color);

	printf("%s", string);
	
	printf(COLOR_RESET);
}