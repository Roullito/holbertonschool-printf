#include "main.h"
#include <stddef.h>
#include <stdarg.h>
/**
 * get_func - Selects the appropriate function based on the format specifier.
 *@c: The format specifier character.
 *Return: NULL
 */

int (*get_func(char c))(va_list)
{
	if (c == 'c')
		return (c_type);
	if (c == 's')
		return (s_type);
	if (c == '%')
		return (p_type);
	if (c == 'd')
		return (d_type);
	if (c == 'i')
		return (i_type);
	return (NULL);
}
