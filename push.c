#include "monty.h"
/**
 *_push - pushes an element to the stack
 *@head: pointer to the first node location in memory
 *@n: data to be pushed into the stack
 *Return: Nothing (void)
 */
void f_push(stack_t **head, unsigned int n)
{
	stack_t *new, *current;

	current = *head;
	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (current)
		current->prev = new;
	new->n = n;
	new->next = current;
	new->prev = NULL;
	*head = new;
}
