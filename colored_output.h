///@file colored_output.h header file contains ANSI escape codes for color definitions and function declaration for colored printing  

#pragma once

///Definition for color reset for print_color();
#define COLOR_RESET "\033[0;0m]"

///Definition for red color for print_color();
#define RED "\033[0;31m"

///Definition for green color for print_color();
#define GREEN "\033[0;32m"

///Definition for yellow color for print_color();
#define YELLOW "\033[0;33m"

///Definition for blue color for print_color();
#define BLUE "\033[0;34m"

///Definition for purple color for print_color();
#define PURPLE "\033[0;35m"

///Definition for cyan color for print_color();
#define CYAN "\033[0;36m"

///Definition for white color for print_color();
#define WHITE "\033[0;37m"

///Colored output
///
/// Uses to color printing text in console
/// @param color defines color, wich will be used to color output
/// @param string that will be printed
void print_color(const char* color, const char* string);