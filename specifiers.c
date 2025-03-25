#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 * c_type - Function to handle the 'c' format specifier (character)
 * @args: The list of arguments passed to the function
 * Return: The number of bytes written (1 byte for the character)
 */
int c_type(va_list args)
{
	char c;

	c = va_arg(args, int);
	return (write(1, &c, 1));
}
/**
 * s_type - Function to handle the 's' format specifier (string)
 * @args: The list of arguments passed to the function
 * Return: The number of characters written
 */
int s_type(va_list args)
{
	char *s = va_arg(args, char *);
	int i = 0;

	if (!s)
		s = "(null)";

	while (s[i])
		write(1, &s[i++], 1);

	return (i);
}
/**
 * p_type - Function to handle the '%' format specifier
 * @args: The list of arguments passed to the function (not used here)
 * Return: The number of bytes written, which is 1 (for the '%' character)
 */
int p_type(va_list args)
{
	(void)args;
	return (write(1, "%", 1));
}

/**
 * d_type - Handles the %d format specifier for numbers between 0 and 99
 * @args: list of variadic arguments (expects an int)
 * Return: The original integer (not the number of characters printed)
 */

int d_type(va_list args)
{
	int d;
	int unite = 0;
	int dizaine = 0;

	d = va_arg(args, int);
	unite = ((d % 10) + '0');
	dizaine = ((d / 10) + '0');

	(write(1, &dizaine, 1));
	(write(1, &unite, 1));

	return (d);
}

/**
 * i_type - Handles the %i format specifier for numbers between 0 and 99
 * @args: list of variadic arguments (expects an int)
 * Return: The original integer (not the number of characters printed)
 */

int i_type(va_list args)
{
	int i;
	int unite = 0;
	int dizaine = 0;

	i = va_arg(args, int);
	unite = ((i % 10) + '0');
	dizaine = ((i / 10) + '0');

	(write(1, &dizaine, 1));
	(write(1, &unite, 1));

	return (i);
}
