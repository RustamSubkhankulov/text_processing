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
#else 
	#define SORTING qsort
#endif


int main(int argc, char *argv[]) { 

	assert(argv[1] != NULL);
	const char* filename = argv[1];
	//const char* filename = "hamlet.txt";

	struct Text text = { 0 };

	char* buf = text_init(filename, &text);

	assert(text.strings != NULL);

	//Sorting from the start of each string
	SORTING((void*)text.strings, text.strings_number, sizeof(struct String), direct_lexicographical_comparator);

	print_strings(&text, "direct_sorted.txt");

	//Sorting from the end of each string
	SORTING((void*)text.strings, text.strings_number, sizeof(struct String), reverse_lexicographical_comparator);
	
	print_strings(&text, "reverse_sorted.txt");

	//Returning sstrings in original order
	SORTING((void*)text.strings, text.strings_number, sizeof(struct String), number_of_string_comparator);

	print_strings(&text, "not_sorted.txt");

	clear_mem(&text, buf);

	print_color(GREEN, "\nProgramm stopped. Go  to files direct_sorted.txt "
				"and reverse_sorted.txt to see results."); 

}