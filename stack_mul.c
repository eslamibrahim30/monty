#include "monty.h"

/**
 * stack_mul - Multiplies the second top element of the stack
 * with the top element of the stack.
 * @stack: a pointer to the head of the stack.
 * @line_number: the current line's number.
 */
void stack_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *p = (stack == NULL ? NULL : *stack);
	stack_t *temp;
	int mul = 0;

	if (p == NULL || p->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	mul = p->prev->n * p->n;
	temp = p;
	p->prev->next = NULL;
	temp->prev->n = mul;
	free(temp);
}
