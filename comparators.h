#pragma once

#include "comparators.h"

static int my_isalpha(char c);

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
/// Is used for comparing strings, compares starting with first letter of each string
/// @param const char* first string to compare
/// @param const char* second string to compare
/// @returns positive value if first string is lexigraphically more than second, 0 if they are equal,
/// negative value if second is lexigraphically more
int direct_lexicographical_comparator(const void* first_struct, const void* second_struct);
