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

	top = *head;
	next = (*head)->next;
	if (top == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", count);
		exit(EXIT_FAILURE);
	}

	top->next = next->next;
	if (top->next)
		top->next->prev = top;
	next->prev = NULL;
	next->next = top;
	top->prev = next;

	*head = next;

}
