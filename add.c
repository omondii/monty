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
	stack_t *top, *temp;
	int len, current;

	top = *head;
	len = 0;

	while (top && top->next)
	{
		top = top->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		exit(EXIT_FAILURE);
	}
	current = top->n + top->next->n;
	top->next->n = current;

	temp = top->next;
	top->next = temp->next;
	free(temp);
}
