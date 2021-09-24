#pragma once

#include "comparators.h"

///Comporator function
/// 
///Used for comparing strings. Starts comparing at the end of string.
/// @param const char* first string to compare
/// @param const char* second string to compare
/// @returns positive value if first string is lexigraphically more than second, 0 if they are equal,
/// negative value if second is lexigraphically more
int reverse_lexicographical_comparator(const void* first_struct, const void* second_struct);

/// Comporator function
/// 
/// Used for comparing strings, compares starting with first letter of each string
/// @param const char* first string to compare
/// @param const char* second string to compare
/// @returns positive value if first string is lexigraphically more than second, 0 if they are equal,
/// negative value if second is lexigraphically more
int direct_lexicographical_comparator(const void* first_struct, const void* second_struct);

/// Comporator function
/// 
/// Compares strings by their number 
/// @param const void* first_struct pointer to the first string to compare
/// @param const void* second_struct pointer to the second string to compare
/// @returns positive value if first string's number is more than second, 0 if they are equal,
/// negative value if second is more
int number_of_string_comparator(const void* first_struct, const void* second_struct);
