#define _CRT_SECURE_NO_WARNINGS
#include "text_processing.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define STRMAXLEN 100

/*
char* s_strcat(char* dest, const char* from) {

	while (*dest != '\0') dest++;
	char* returning_pointer = dest;
	while ((*dest++ = *from++) != '\0') continue;

	return returning_pointer;
}
//====================================================
int s_getline(char* line, int lim, FILE* fp) {

	if (fgets(line, lim, fp) == NULL)
		return 0;
	else return strlen(line);
}
//==================================================
char* s_strncat(char* dest, const char* from, int n) {

	while (*dest != '\0') dest++;
	char* returning_pointer = dest;

	while (n-- > 0 && (*dest++ = *from++) != '\0') continue;
	if (n < 0) *dest = '\0';

	return returning_pointer;
}
//==================================================
size_t s_strlen(const char* string) {

	size_t len = 0;
	while (*string++ != '\0') len++;

	return len;
}
//==================================================
int s_puts(const char* string) {

	if (*string == '\0') return EOF;

	while (*string != '\0') putchar(*string++);
	putchar('\n');

	return 1;
}
//==================================================
char* s_strcpy(char* dest, const char* from) {

	char* returning_pointer = dest;
	while ((*dest++ = *from++) != '\0') continue;

	return returning_pointer;
}
//==================================================
char* s_strncpy(char* dest, const char* from, int n) {

	char* returning_pointer = dest;
	while (n-- > 0 && (*dest++ = *from++) != '\0') {
		continue;
	}
	if (n < 0) *dest = '\0';

	return returning_pointer;
}
//==================================================
char* s_strchr(char* string, int symbol) {
	while (*string != '\0') {
		if (*string == symbol) return string;
		string++;
	}
	return NULL;
}
//==================================================
char* s_fgets(char* dest, int num, FILE* fp) {

	while (num-- > 0 && (*dest = getc(fp)) != EOF && *dest++ != '\n') {
	}
	if (*dest == EOF) return NULL;
	if (num < 0) *dest = '\0';
	return dest;
}
//==================================================
char* s_strdup(const char* string) {

	if (string == NULL) return NULL;
	char* copiedstr = (char*)calloc(s_strlen(string) + 1, sizeof(char));
	if (copiedstr == NULL) return NULL;
	s_strcpy(copiedstr, string);

	return copiedstr;
}
//==================================================
int s_strcmp(const char* firstline, const char* secondline) {

	while (*firstline == *secondline) {
		firstline++;
		secondline++;
	}
	if (!isalpha(*firstline) && !isalpha(*secondline)) {
		firstline++;
		secondline++;
		return s_strcmp(firstline, secondline);
	}
	if (!isalpha(*firstline) && isalpha(*secondline)) {
		firstline++;
		return s_strcmp(firstline, secondline);
	}
	if (isalpha(*firstline) && !isalpha(*secondline)) {
		secondline++;
		return s_strcmp(firstline, secondline);
	}
	if (*firstline == '\0') return 0;
	return *firstline - *secondline;
} */
/*
//============================================================================
long count_lines(FILE* fp) {

	if (fp == NULL) return -1;

	char ch = 0;
	long lines_count = 0;
	while ((ch = getc(fp)) != EOF) {
		if (ch == '\n') lines_count++;
	}
	rewind(fp);
	return lines_count+1;
}

//============================================================================
char** read_file(FILE* fp, long lines_number) {

	char** lines = (char**) malloc( lines_number * STRMAXLEN * sizeof(char) );

	char** returning_pointer = lines;

	for (long i = 0; i < lines_number; i++) {

		char temp[STRMAXLEN];
		fgets(temp, STRMAXLEN, fp);

		lines[i] = (char*) calloc( strlen(temp) + 1, sizeof(char) );
		strcpy(lines[i], temp);
	}
	fclose(fp);

	return returning_pointer;
}

//============================================================================
void sort_lines(char** lines, long lines_number) {

	for (int i = 0; i< lines_number - 1; i++)

		for (int j = i + 1; j < lines_number; j++)

			if (strcmp(lines[i], lines[j]) > 0) {

				char* temp = lines[i];
				lines[i] = lines[j];
				lines[j] = temp;
			}
}

//============================================================================
void reverse_sort_lines(char** lines, long lines_number) {

	reverse_lines(lines, lines_number);
	sort_lines(lines, lines_number);
	reverse_lines(lines, lines_number);
}

//============================================================================
void reverse_line(char* start, int len){
	char* end = start + len - 1;
	while (start - end < 0) {
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}
//============================================================================
void reverse_lines(char** lines, long lines_number) {
	for (long i = 0; i < lines_number; i++) {

		char* start = lines[i];
		char* end = lines[i] + strlen(lines[i]) - 1;

		while (end - start > 0) {
			char temp = *start;
			*start = *end;
			*end = temp;
			start++;
			end--;
		}
	}
}
//============================================================================
void save_result(char** lines, long lines_number, char* filename) {

	FILE* fp = fopen(filename, "w");
	for (int i = 0; i < lines_number; i++) fputs(lines[i], fp);
	fclose(fp);
}
*/
long file_size(FILE* fp) {

	fseek(fp, 0L, SEEK_END);
	long size = ftell(fp);
	rewind(fp);

	return size;
}

char* read_file(long size, FILE* fp) {

	char* buf = (char*)malloc(size);
	fread(buf, sizeof(char), size, fp);

	return buf;
}

long count_strings(char* buf) {

	char* n_pointer = buf;
	long strings_number = 0;

	while ((n_pointer = strchr(n_pointer, '\n')) != NULL) {

		strings_number++;
		n_pointer++;
	}
	return strings_number;
}

void read_data(char* buf, struct Text* text) {

	char* string_begin = buf;

	for (int string_count = 1; string_count < text->strings_number; string_count++) {

		char* n_pointer = strchr(buf, '\n');
		*n_pointer = '\0';

		text->strings->lenght = n_pointer - string_begin + 1;
		text->strings->data = (char*)calloc(text->strings->lenght, sizeof(char));
		strcpy(text->strings->data, string_begin);

		string_begin = n_pointer + 1;
		text->strings++;
	}
}

void text_init(const char* filename, struct Text* text) {

	FILE* fp = fopen(filename, "r");

	text->size = file_size(fp);

	char* buf = read_file(text->size, fp);

	fclose(fp);

	puts(buf);

	text->strings_number = count_strings(buf);

	printf("Number of strings %ld\n", text->strings_number);
	printf("File size: %ld\n", text->size);

	//read_data(buf, text);
}