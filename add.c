#include "monty.h"
#include <stdlib.h>
/**
 *_sum - adds the top two elements of the stack
 *@head: pointer to the top element in a stack
 *@count: line number
 *Return: Nothing (void)
 */
void f_sum(stack_t **head, unsigned int count)
{
	stack_t *top;
	int len, current;

	top = *head;
	count = 0;
	while (top)
	{
		top = top->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(com.file);
		free(com.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = top->n + top->next->n;
	top->next->n = current;
	*head = top->next;
	free(top);
}
