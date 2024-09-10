#include "monty.h"

/**
 * stack_push - Pushes an element to the stack.
 * @stack: a pointer to the head of the stack.
 * @value: the value to be pushed.
 */
void stack_push(stack_t **stack, int value)
{
	stack_t *endadd = NULL;
	stack_t *node = NULL;

	if (stack == NULL)
		return;
	endadd = (stack_t *)malloc(sizeof(stack_t));
	if (endadd == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	endadd->n = value;
	endadd->next = NULL;
	if (*stack == NULL)
	{
		*stack = endadd;
		endadd->prev = NULL;
	}
	else
	{
		node = *stack;
		while (node->next != NULL)
		{
			node = node->next;
		}
		node->next = endadd;
		endadd->prev = node;
	}
}
