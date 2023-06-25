#include "monty.h"
/**
 *free_stack - frees a doubly linked list
 *@head: pointer to first element in stack
 */
void free_stack(stack_t *head)
{
	stack_t *current = NULL;

	while (head != NULL)
	{
		current = head->next;
		free(head);
		head = current;
	}
}
