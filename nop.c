#include "monty.h"
/**
 *f_nop - does nothing
 *@head: pointer to the first element in stack
 *@count: line number
 */
void f_nop(stack_t **head, unsigned int count)
{
	(void) head;
	(void) count;
}
/**
 *readfile- reads the opened file
 *@file: file to open
 *Return: status
 */
int readfile(FILE *file)
{
	char *content = NULL;
	size_t size = 0;
	unsigned int count = 0;
	stack_t *stack = NULL;
	int status = EXIT_SUCCESS;
	ssize_t line_length;

	while (((line_length = getline(&content, &size, file)) != -1))
	{
		count++;
		content[line_length - 1] = '\0';
		execute(&stack, content, count);
		if (global_var->status == EXIT_FAILURE)
		{
			status = EXIT_FAILURE;
			break;
		}
	}
	free(content);
	free_stack(stack);
	return (status);
}
