#pragma once

void static swap(char* first, char* second, size_t size);

/// Uses comparator function for sorting strings
/// 
/// @param struct Text* text pointer to the text structure
/// @param function pointer 
void sort_strings(struct Text* text,
	int (*comparator)(const void* first_struct, const void* second_struct));

void my_qsort(void* base_el, size_t n, size_t size, int (*cmp) (const void* , const void*));
