#pragma once

///Function that process number of error 
///
///@param error_num number of an error
///@param ine_number number of line where an error occured
///@param const char* func_name name of the function where an error occured
void process_error(int error_num, int line_number, const char* func_name);