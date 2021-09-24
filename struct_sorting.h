#pragma once

/// Data exchage function
/// 
/// Static function used only by sorting algorithms
/// <param name="first"></param>
/// <param name="second"></param>
/// <param name="size"></param>
void static swap(char* first, char* second, size_t size);

/// Uses comparator function for sorting strings
/// 
/// Algorithm used for sorting is insertion sort
/// @param struct Text* text pointer to the text structure
/// @param function pointer 
void sort_strings(struct Text* text,
	int (*comparator)(const void* first_struct, const void* second_struct));

/// Standart library qsort analogue
/// 
/// @param void* base_el pointer to the start of array of comparable items
/// @param int n number of comparable items
/// @param int size size of each item
/// @param cmp comparator function
void my_qsort(void* base_el, int n, int size, int (*cmp) (const void* , const void*));

static long my_partition(char* base, long left, long right, int size, int (*cmp) (const void*, const void*));