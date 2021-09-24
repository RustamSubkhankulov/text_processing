#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "text_processing.h"

//=========================================================================================
int direct_lexicographical_comparator(const void* first_struct, const void* second_struct) {

	assert(first_struct != NULL);
	assert(second_struct != NULL);

	const struct String* first_struct_ptr  = (const struct String*) first_struct;

	const struct String* second_struct_ptr = (const struct String*) second_struct;

	const char* first_string_ptr  = first_struct_ptr ->data;
	const char* second_string_ptr = second_struct_ptr->data;


	while (*first_string_ptr != '\0' && *second_string_ptr != '\0' ) {

		if (!isalpha((char)*first_string_ptr)) {

			first_string_ptr++;
			continue;
		}
		if (!isalpha((char)*second_string_ptr)) {

			second_string_ptr++;
			continue;
		}
		if (*first_string_ptr == *second_string_ptr\
			                  && *first_string_ptr  != '\0'\
			                  && *second_string_ptr != '\0') {

			first_string_ptr++;
			second_string_ptr++;

			continue;
		}

		if (*first_string_ptr - *second_string_ptr == 0) {

			return 0;
		}
		return ((*first_string_ptr - *second_string_ptr) < 0) ? -1 : 1;
	}

	return 0;
}


//===========================================================================================
int reverse_lexicographical_comparator(const void* first_struct, const void* second_struct) {

	assert(first_struct  != NULL);
	assert(second_struct != NULL);

	const struct String* first_struct_ptr  = (struct String*) first_struct;
	const struct String* second_struct_ptr = (struct String*) second_struct;

	const char* first_string_ptr  = first_struct_ptr ->data;
	const char* second_string_ptr = second_struct_ptr->data;

	const char* first_string_end  = first_string_ptr  + first_struct_ptr ->length - 1;
	const char* second_string_end = second_string_ptr + second_struct_ptr->length - 1;

	while (first_string_end != first_string_ptr && second_string_end != second_string_ptr) {

		if (!isalpha((char)*first_string_end)) {

			first_string_end--;
		}
		if (!isalpha((char)*second_string_end)) {

			second_string_end--;
		}
		if (*first_string_end  == *second_string_end\
		  && first_string_end  !=  first_string_ptr \
		  && second_string_end !=  second_string_ptr) {

			first_string_end--;
			second_string_end--;
			continue;
		}

		if (*first_string_end - *second_string_end == 0) {

			return 0;
		}
		return ((*first_string_end - *second_string_end) < 0) ? -1 : 1;
	}

	return 0;
}

//=======================================================================================

int number_of_string_comparator(const void* first_struct, const void* second_struct) {

	assert(first_struct  != NULL);
	assert(second_struct != NULL);


	const struct String* first_struct_ptr  = (const struct String*) first_struct;
	const struct String* second_struct_ptr = (const struct String*)second_struct;

	long diff = first_struct_ptr->number - second_struct_ptr->number;

	if (diff > 0) return  1;
	if (diff < 0) return -1;
	return 0;
}