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

	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}

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
 * d_type - Handles the %d format specifier
 * @args: list of variadic arguments
 * Return: The original integer
 */

int d_type(va_list args)
{
	int d;
	int i = 0;
	int j = 0;
	int count = 0;
	unsigned int posi_d;
	char tab[12];

	d = va_arg(args, int);

	if (d < 0)
	{
		write(1, "-", 1);
		count++;
		posi_d = -d;
	}

	else
		posi_d = d;

	if (posi_d == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (posi_d > 0)
	{
		tab[i] = ((posi_d % 10) + '0');
		posi_d = posi_d / 10;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
		count = count + write(1, &tab[j], 1);

	return (count);
}
