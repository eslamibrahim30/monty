#include "monty.h"

/**
 * stack_rotl - Rotates the stack to the top.
 * @stack: a pointer to the head of the stack.
 * @line_number: the current line's number.
 */
void stack_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr_end = NULL;
	int temp = 0;

	if (stack == NULL || *stack == NULL || line_number == 0)
		return;
	ptr_end = *stack;
	while (ptr_end->next != NULL)
	{
		ptr_end = ptr_end->next;
	}
	temp = ptr_end->n;
	while (ptr_end->prev != NULL)
	{
		ptr_end->n = ptr_end->prev->n;
		ptr_end = ptr_end->prev;
	}
	ptr_end->n = temp;
}
