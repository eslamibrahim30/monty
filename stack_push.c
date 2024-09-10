#include "monty.h"

/**
 * stack_push - Pushes an element to the stack.
 * @stack: a pointer to the head of the stack.
 * @value: the value to be pushed.
 */
void stack_push(stack_t **stack, int value)
{
	stack_t *end = NULL;
	stack_t *node = NULL;

	if (stack == NULL)
		return;
	end = (stack_t *)malloc(sizeof(stack_t));
	if (end == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	end->n = value;
	end->next = NULL;
	if (*stack == NULL)
	{
		*stack = end;
		end->prev = NULL;
	}
	else
	{
		node = *stack;
		while (node->next != NULL)
		{
			node = node->next;
		}
		node->next = end;
		end->prev = node;
	}
}
