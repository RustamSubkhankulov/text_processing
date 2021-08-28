#define _CRT_SECURE_NO_WARNINGS
#include "text_processing.h"

int main(void) { // argv
	/*
	FILE* fp = fopen("hamlet.txt", "r"); // struct Text

	long lines_number = count_lines(fp);
	char** lines = read_file(fp, lines_number); // struct String in text fread fseek(SEEK_END) ftell rewind

	save_result(lines, lines_number, "sorted.txt");

	reverse_sort_lines(lines, lines_number);
	save_result(lines, lines_number, "reverse_sorted.txt");

	free(lines);
	*/
	struct Text text = { 0 };

	text_init("hamlet.txt", &text);


	printf("Programm stopped.\n");
}