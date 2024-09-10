#include "monty.h"

/**
 * main - Entry point
 * @argc: the number of arguments of the main function
 * @argv: the actual arguments of the main function
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	FILE *file = NULL;
	char *file_name = NULL;
	char *line = NULL;
	stack_t *our_stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_name = argv[1];
	file = fopen(file_name, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	line = (char *)malloc(MAX_LEN);
	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	line_number = 0;
	while (!feof(file) && !ferror(file))
	{
		if (fgets(line, MAX_LEN, file) != NULL)
		{
			line_number++;
			execLine(line, &our_stack, line_number);
		}
	}
	free(line);
	freeStack(our_stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
