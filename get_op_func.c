#include "monty.h"

/**
 * get_op_func - Selects the correct function to perform
 * the operation asked by the user
 * @s: the operator passed as argument to the program
 *
 * Return: a pointer to the function that corresponds to
 * the operator given as a parameter
 */
void (*get_op_func(char *s))(stack_t **, unsigned int)
{
	instruction_t *instructions = NULL;
	int i = 0;
	void (*func)(stack_t **, unsigned int);

	instructions = malloc(14 * sizeof(instruction_t));
	if (instructions == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	initInstructions(instructions);
	for (i = 0; i < 14; i++)
	{
		if (strcmp(s, instructions[i].opcode) == 0)
		{
			func = instructions[i].f;
			free(instructions);
			return (func);
		}
	}
	free(instructions);
	return (NULL);
}
