#include "monty.h"
/**
 *f_display - prints all the values on the stack, from the top
 *@head: pointer that holds the location of the top element in the stack
 *@count: line number
 *Return: Nothing(void)
 */
void f_display(stack_t **head, unsigned int count)
{
	stack_t *top;
	(void)count;

	top = *head;
	if (top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		exit(EXIT_FAILURE);
	}
	while (top)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}
