#include "monty.h"

/**
 * isnumber - Checks if a string is a number or not.
 * @str: the given string.
 *
 * Return: 1 If it is a number, 0 Otherwise.
 */
int isnumber(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}
