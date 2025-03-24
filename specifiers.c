#include "main.h"
#include <unistd.h>
#include <stdarg.h>

int c_type(va_list args)
{
	char c;

	c = va_arg(args, int);
	return (write(1, &c, 1));
}

int s_type(va_list args)
{
	char *s = va_arg(args, char *);
	int i = 0;

	if(!s)
		s = "(null)";

	while (s[i])
		write(1, &s[i++], 1);

	return (i);
}

int p_type(va_list args)
{
	(void)args;
	return (write(1, "%", 1));
}
