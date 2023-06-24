#include "monty.h"
/**
 *free_stack - frees a doubly linked list
 *@head: pointer to first element in stack
 */
void free_stack(stack_t *head)
{
	stack_t *current;

	current = head;
	while (head != NULL)
	{
		current = head->next;
		head = head->next;
		free(current);
	}
}
