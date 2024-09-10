#include "monty.h"

/**
 * stack_rotr - Rotates the stack to the bottom.
 * @stack: a pointer to the head of the stack.
 * @line_number: the current line's number.
 */
void stack_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr_start = NULL;
	int temp = 0;

	if (stack == NULL || *stack == NULL || line_number == 0)
		return;
	ptr_start = *stack;
	temp = ptr_start->n;
	while (ptr_start->next != NULL)
	{
		ptr_start->n = ptr_start->next->n;
		ptr_start = ptr_start->next;
	}
	ptr_start->n = temp;
}
