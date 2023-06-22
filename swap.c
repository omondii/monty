#include "monty.h"
/**
 *_swap - swaps the top two elements of the stack
 *@head: pointer to top item in the stack
 *@count: line number
 *Return: Nothing (void)
 */
void f_swap(stack_t **head, unsigned int count)
{
	stack_t *top;
	int len, current;

	top = *head;
	len = 0;

	while (top)
	{
		top = top->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(com.file);
		free(com.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = top->n;
	top->n = top->next->n;
	top->next->n = current;
}
