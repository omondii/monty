#include "monty.h"
/**
 *f_pop - removes the top element of the stack
 *@head: pointer to the first items location in memory
 *@count: line number
 *Return: Nothing (void)
 */
void f_pop(stack_t **head, unsigned int count)
{
	stack_t *top;

	top = *head;
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		exit(EXIT_FAILURE);
	}
	top = *head;
	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;
	free(top);
}
