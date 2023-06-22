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
	int current;

	top = *head;
	if (top == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", count);
		return;
	}

	next = top->next;
	if (next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", count);
		return;
	}

	current = top->n;
	top->n = next->n;
	next->n = current;
}
