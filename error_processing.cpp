#define _CRT_SECURE_NO_WARNINGS

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "error_processing.h"

//================================================
void process_error(int error_num, int line_number, const char* func_name) {

	if (error_num != 0) {
		fprintf(stderr, "Function: %s, line %d. An error occured: %s.\n", \
																func_name, \
																line_number,\
																strerror(error_num));
		exit(1);
	}
}