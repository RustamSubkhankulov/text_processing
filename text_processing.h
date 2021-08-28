#pragma once
#include <stddef.h>
#include <stdio.h>

/*
char* s_strcat(char* dest, const char* from);

char* s_strncat(char* dest, const char* from, int n);

size_t s_strlen(const char* string);

int s_puts(const char* string);

char* s_strcpy(char* dest, const char* form);

char* s_strncpy(char* dest, const char* form, int n);

char* s_strchr(char* string, int symbol);

char* s_fgets(char* dest, int num, FILE* fp);

char* s_strdup(const char* string);
//s_getline
*/

/*
int count_lines(FILE* fp);

char** read_file(FILE* fp, long lines_number);

void sort_lines(char** lines, long lines_number);

void reverse_sort_lines(char** lines, long lines_number);

void reverse_lines(char**, long lines_number);

void reverse_line(char* start, int len);

void save_result(char** lines, int lines_number, char* filename);
*/
struct String {
	char* data;
	long lenght;
};

struct Text {
	long strings_number;
	struct String* strings;
	long size;
};

void text_init(const char* filename, struct Text* text);

long file_size(FILE* fp);

long count_strings(char* buf);

void read_data(char* buf, struct Text* text);