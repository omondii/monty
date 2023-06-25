#include "monty.h"
/**
 *f_push - pushes data to the stack
 *@head: pointer to the first node location in memory
 *@count: data to be pushed into the stack
 *Return: Nothing (void)
 */
void f_push(stack_t **head, unsigned int count)
{
	stack_t *new = NULL;

	global_var->status = EXIT_SUCCESS;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		global_var->status = EXIT_FAILURE;
	}
	else
	{
		if (global_var->argument == NULL ||
		    isdigit(global_var->argument[0]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			free(new);
			global_var->status = EXIT_FAILURE;
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
