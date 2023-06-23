#include "monty.h"
/**
 *execute - parses the entered command, and compares each token to
 *to moncmd[]
 *@stack: pointer to a stack implementation
 *@content: arguments to parse and compare
 *@count: line number being executed
 *@file: pointer to the file being operatd on
 *Return: on success (0), on fail (1)
 */
void execute(stack_t **stack, char *content, unsigned int count)
{
	int i;

	instruction_t opcomm[] = {
		{"push", f_push}, {"pall", f_display},
		{"pint", f_peek}, {"pop", f_pop},
		{"swap", f_swap}, {"add", f_sum},
		{"stack", f_stack}, {NULL, NULL}
	};
	for (i = 0; opcomm[i].opcode; i++)
	{
		if (strcmp(content, opcomm[i].opcode) == 0)
		{
			opcomm[i].f(stack, count);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", count, content);
	exit(EXIT_FAILURE);
}
