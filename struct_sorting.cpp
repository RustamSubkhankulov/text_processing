#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "text_processing.h"
#include "error_processing.h"

//===========================================================================================

void static swap(char* first, char* second, size_t size) {

	assert(first != NULL);
	assert(second != NULL);

	char* temp = (char*)calloc(1, size);
	assert(temp != NULL);

	memcpy(temp, first, size);
	memcpy(first, second, size);
	memcpy(second, temp, size);

	free(temp);
	process_error(errno, __LINE__, __func__);
}

////===========================================================================================
//
//void string_swap(struct String* first_string, struct String* second_string) {
//
//	assert(first_string != NULL);
//	assert(second_string != NULL);
//
//	struct String temp = { 0 };
//
//	memcpy(&temp, first_string, sizeof(struct String));
//	memcpy(first_string, second_string, sizeof(struct String));
//	memcpy(second_string, &temp, sizeof(struct String));
//
//	process_error(errno, __LINE__, __func__);
//}
//===========================================================================================

//===========================================================================================
void sort_strings(struct Text* text,
	int (*comparator)(const void* first_struct, const void* second_struct)) {

	assert(text != NULL);
	assert(comparator != NULL);

	for (int i = 1; i < text->strings_number; i++)

		for (int j = i; j > 0 && comparator((const void*)&text->strings[j - 1], \
											(const void*)&text->strings[j]) > 0;\
																	        j--) {

			swap((char*)&text->strings[j - 1], (char*)&text->strings[j], sizeof(struct String));
		}

	process_error(errno, __LINE__, __func__);
}

//===========================================================================================

void my_qsort(void *base_el, size_t n, size_t size, int (*cmp) (const void* , const void* )) {

	char* base = (char*)base_el;
	long left = 0;
	long right = n - 1;

	if (left >= right) return;

	swap(&base[left], &base[((left + right)/(size * 2))*size], size);
	int last = left;

	for (int i = left + size; i <= right; i += size)
		if (cmp((const void*)&base[i], (const void*)&base[right]) > 0) {
			swap(&base[last], &base[i], size);
			last += size;
		}
	swap(&base[left], &base[last], size);

	my_qsort((void*)&base[left], last - size -left, size, cmp);
	my_qsort((void*)&base[last + size], right - size - last, size, cmp);
}

