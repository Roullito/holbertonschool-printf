#include "main.h"
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	int i;
	int count = 0;
	va_list args;
	int (*func)(va_list);

	va_start(args, format);

	for(i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			func = get_func(format[i]);

			if (func)
			{
				count += func(args);
				i++;
			}

			else
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
			}

		}
			write(1, &format[i], 1);
			count++;
	}

	va_end(args);
	return (count);
}
