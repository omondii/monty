#include "monty.h"
/**
 *f_peek - prints the value at the top of the stack
 *@head: pointer to the first items location in memory
 *@count: line number
 *Return: Nothing(void)
 */
void f_peek(stack_t **head, unsigned int count)
{
	global_var->status = EXIT_SUCCESS;
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		global_var->status = EXIT_FAILURE;
	}
	printf("%d\n", (*head)->n);
}
