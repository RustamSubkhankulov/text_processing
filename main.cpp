#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <assert.h>

#include "text_processing.h"
#include "comparators.h"
#include "colored_output.h"
#include "struct_sorting.h"

#define MYSORT

#ifdef MYSORT 
	#define SORTING my_qsort
#endif

#ifndef MYSORT
	#define SORTING qsort
#endif

int main(int argc, char *argv[]) { 

	//assert(argv[1] != NULL);
	//const char* filename = argv[1];
	const char* filename = "hamlet.txt";

	struct Text text = { 0 };

	char* buf = text_init(filename, &text);

	print_strings(&text, "not_sorted.txt");

	assert(text.strings != NULL);
	SORTING((void*)text.strings, text.strings_number, sizeof(struct String), direct_lexicographical_comparator);

	//sort_strings(&text, direct_lexicographical_comparator); 
	print_strings(&text, "direct_sorted.txt");

	//SORTING((void*)text.strings, text.strings_number, sizeof(struct String), reverse_lexicographical_comparator);
	
	//sort_strings(&text, reverse_lexicographical_comparator);
	//print_strings(&text, "reverse_sorted.txt");

	clear_mem(&text, buf);

	print_color(GREEN, "\nProgramm stopped. Go  to files direct_sorted.txt "
				"and reverse_sorted.txt to see results.\n"); 

}