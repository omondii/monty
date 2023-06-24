#include "monty.h"
/**
 *f_push - pushes an element to the stack
 *@head: pointer to the first node location in memory
 *@n: data to be pushed into the stack
 *Return: Nothing (void)
 */
void f_push(stack_t **head, unsigned int count)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (global_var->argument == NULL ||
		    isdigit(global_var->argument[0]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			free(new);
			exit(EXIT_FAILURE);
		}
		else
		{
			new->n = atoi(global_var->argument);
			new->prev = NULL;
			new->next = *head;
			*head = new;
		}
	}
}
