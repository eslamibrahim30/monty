#include "monty.h"

/**
 * execLine - Executes a given line of the program.
 * @line: an array of chars which contains the given line.
 * @stack: a pointer to the head of the stack on which
 * the operations will execute.
 * @line_number: the current line's number
 */
void execLine(char line[MAX_LEN], stack_t **stack, unsigned int line_number)
{
	char **words = NULL;
	int word_counter = 0;
	int i = 0;
	void (*func)(stack_t **, unsigned int) = NULL;

	words = (char **)malloc(MAX_LEN * sizeof(char *));
	if (words == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	splitString(line, words, &word_counter);
	if (word_counter != 0)
	{
		if (word_counter == 1 && strcmp(words[0], "push") != 0)
		{
			func = get_op_func(words[0]);
			if (func == NULL)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, words[0]);
				exit(EXIT_FAILURE);
			}
			(*func)(stack, line_number);
		}
		else if ((word_counter == 1 || (word_counter == 2 && !isnumber(words[1])))
		&& strcmp(words[0], "push") == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		else if (word_counter == 2 && strcmp(words[0], "push") == 0)
		{
			stack_push(stack, atoi(words[1]));
		}
	}
	for (i = 0; i < word_counter; i++)
		if (words[i] != NULL)
			free(words[i]);
	free(words);
}
