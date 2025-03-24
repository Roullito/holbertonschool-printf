#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int (*get_func(char c))(va_list);
int c_type(va_list args);
int s_type(va_list args);
int p_type(va_list args);

#endif
