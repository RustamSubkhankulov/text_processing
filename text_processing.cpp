#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

#include "text_processing.h"
#include "error_processing.h"

//#define LOGGING
//#define PRINTNUMBEROFLINE

//=============================================================================
char* text_init(const char* filename, struct Text* text) {

	//filename = "hamlet.txt";

	assert(filename != NULL);
	assert(text != NULL);

	errno = 0;

	char* buf = file_to_buf_copy(filename, text);

	strings_init(buf, text);

	#ifdef LOGGING
		printf("Number of strings read is %ld\n Size of the file: %ld.\n", text->strings_number, text->size);
	#endif

	return buf;
}

//============================================================================
char* file_to_buf_copy(const char* filename, struct Text* text) {

	assert(filename != NULL);
	assert(text != NULL);

	FILE* fp = fopen(filename, "rb");
	process_error(errno, __LINE__, __func__);

	text->size = file_size(fp);
	char* buf = copy_data_to_buf(text->size, fp);

	fclose(fp);
	process_error(errno, __LINE__, __func__);

	#ifdef LOGGING
		printf("File %s copied to buffer. Size of copied data is %ld.\n\n", filename, text->size);
	#endif

	return buf;
}

//=============================================================================
long file_size(FILE* fp) {

	assert(fp != NULL);

	int fseek_return = fseek(fp, 0L, SEEK_END);
	process_error(errno, __LINE__, __func__);

	long size = ftell(fp);
	process_error(errno, __LINE__, __func__);

	rewind(fp);
	process_error(errno, __LINE__, __func__);

	return size;
}

//============================================================================
char* copy_data_to_buf(long size, FILE* fp) {

	assert(fp != NULL);

	char* buf = (char*)calloc(size + 1, sizeof(char));
	assert(buf != NULL);

	long end_of_file = fread(buf, sizeof(char), size, fp);
	assert(end_of_file == size);

	buf[end_of_file] = '\0';

	return buf;
}

//============================================================================
long count_strings(char* buf) {

	assert(buf != NULL);

	char* n_pointer = buf;
	long strings_number = 0;

	while ((n_pointer = strchr(n_pointer, '\n')) != NULL) {

		strings_number++;
		n_pointer++;
	}

	#ifdef LOGGING
		printf("Strings counted. Number of strings %ld.\n", strings_number);
	#endif

	return strings_number;
}

//============================================================================
void strings_init(char* buf, struct Text* text) {

	assert(buf != NULL);
	assert(text != NULL);

	text->strings_number = count_strings(buf);

	text->strings = (struct String*)calloc(text->strings_number,
		sizeof(struct String));
	assert(text->strings != NULL);

	struct String* starting_pointer = text->strings;

	char* string_start = strtok(buf, "\n");
	assert(string_start != NULL);

	text->strings_number = 0;
	long length = 0;

	while (string_start != NULL) {

		if (does_contain_letters(string_start)) { 

			string_start = string_skip_blank(string_start);
			length = strlen(string_start);
			text->strings_number++;

			string_init(text->strings, length, string_start, text->strings_number);

			text->strings++;
		}
		string_start = strtok(NULL, "\n");
	}

	process_error(errno, __LINE__, __func__);

	text->strings = starting_pointer;

	#ifdef LOGGING
		printf("Strings (expept empty strings) initializated."
			   " Number of initializated strings %ld\n", text->strings_number);
	#endif


}

//===========================================================================
int does_contain_letters(const char* string) {

	assert(string != NULL);

	const char* string_ptr = string;
	while (*string_ptr != '\0') {

		if (isalpha(*string_ptr)) return 1;
		string_ptr++;
	}

	return 0;
}

//============================================================================
char* string_skip_blank(char* string) {

	assert(string != NULL);

	while (*string == ' ') 
		    string++;

	return string;
}

//============================================================================
void string_init(struct String* strings, long length, char* data, long number) {

	assert(strings != NULL);
	assert(data != NULL);

	strings->length = length;
	strings->data   = data;
	strings->number = number;

	process_error(errno, __LINE__, __func__);
}

//==============================================================================================
void clear_strings(struct Text* text) {

	assert(text != NULL);

	free(text->strings);
	process_error(errno, __LINE__, __func__);

	#ifdef LOGGING
		printf("Memory allocated for strings is free.\n");
	#endif
}

//===========================================================================================

void print_strings(struct Text* text, const char* filename) {

	assert(text != NULL);
	assert(filename != NULL);

	FILE* fp = fopen(filename, "wb");
	process_error(errno, __LINE__, __func__);

	for (long string_count = 0; string_count < text->strings_number; string_count++) {


		#ifdef PRINTNUMBEROFLINE
			fprintf(fp, "%5ld %5ld", text->strings[string_count].number, \
									text->strings[string_count].length);
		#endif

		fprintf(fp, " %s\n", text->strings[string_count].data);

	}
	process_error(errno, __LINE__, __func__);

	fclose(fp);
	
	process_error(errno, __LINE__, __func__);
}

//============================================================================================

void clear_buf(char* buf) {
	
	assert(buf != NULL);

	free(buf);
	process_error(errno, __LINE__, __func__);
}


//==============================================================================================

void clear_mem(struct Text* text, char* buf) {

	assert(text != NULL);
	assert(buf != NULL);

	clear_strings(text);
	clear_buf(buf);
}

//==============================================================================================