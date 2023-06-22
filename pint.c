#include "monty.h"
/**
 *_peek - prints the value at the top of the stack
 *@head: pointer to the first items location in memory
 *@count: line number
 *Return: Nothing(void)
 */
void f_peek(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(com.file);
		free(com.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
