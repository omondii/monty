#include "monty.h"
/**
 *f_swap - swaps the top two elements of the stack
 *@head: pointer to top item in the stack
 *@count: line number
 *Return: Nothing (void)
 */
void f_swap(stack_t **head, unsigned int count)
{
	stack_t *top, *next;

	if (!head || !(*head) || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		exit(EXIT_FAILURE);
	}

	top = *head;
	next = top->next;

	top->next = next->next;
	top->prev = next;
	next->next = top;
	next->prev = NULL;

	if (top->next != NULL)
		top->next->prev = top;
	*head = next;
}
