#include "main.h"
#include <stddef.h>
#include <stdarg.h>

int (*get_func(char c))(va_list)
{
	if (c == 'c') return (c_type);
	if (c == 's') return (s_type);
	if (c == '%') return (p_type);
	return (NULL);
}
