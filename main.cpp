#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <assert.h>

#include "text_processing.h"
#include "comparators.h"
#include "colored_output.h"
#include "struct_sorting.h"

int main(int argc, char *argv[]) { 

	struct Text text = { 0 };
	//const char* filename = argv[1];
	const char* filename = "hamlet.txt";

	char* buf = text_init(filename, &text);

	print_strings(&text, "not_sorted.txt");

	printf("Before\n");

	assert(text.strings != NULL);

	qsort((void*)text.strings, text.strings_number, sizeof(struct String), direct_lexicographical_comparator);
	printf("after\n");

	//sort_strings(&text, direct_lexicographical_comparator); 
	//print_strings(&text, "direct_sorted.txt");

	//qsort((void*)text.strings, text.strings_number, sizeof(struct String*), reverse_lexicographical_comparator);
	
	//sort_strings(&text, reverse_lexicographical_comparator);
	//print_strings(&text, "reverse_sorted.txt");

	clear_mem(&text, buf);

	print_color(GREEN, "\nProgramm stopped. Go  to files direct_sorted.txt "
				"and reverse_sorted.txt to see results.\n"); 

}
