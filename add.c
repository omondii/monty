#include "monty.h"
#include <stdlib.h>
/**
 *f_sum - adds the top two elements of the stack
 *@head: pointer to the top element in a stack
 *@count: line number
 *Return: Nothing (void)
 */
void f_sum(stack_t **head, unsigned int count)
{
	stack_t *top, *next;

	if (!head || !(*head) || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		exit(EXIT_FAILURE);
	}
	top = *head;
	next = top->next;

	next->n += top->n;
	*head = next;
	next->prev = NULL;

	free(top);
}
