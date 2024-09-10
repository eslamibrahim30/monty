#include "monty.h"

/**
 * freeStack - Frees a stack_t list.
 * @head: the head of the linked list.
 */
void freeStack(stack_t *head)
{
	if (head == NULL)
		return;
	if (head->next == NULL)
	{
		free(head);
		return;
	}
	freeStack(head->next);
	free(head);
}
