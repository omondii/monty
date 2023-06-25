#include "monty.h"
/**
 *execute - parses the entered command, and compares each token to
 *to moncmd[]
 *@stack: pointer to a stack implementation
 *@content: arguments to parse and compare
 *@count: line number being executed
 *Return: on success (0), on fail (1)
 */
void execute(stack_t **stack, char *content, unsigned int count)
{
	unsigned int i;
	char *opcode, *argument = NULL;

	instruction_t opcomm[] = {
		{"push", f_push}, {"pall", f_display},
		{"pint", f_peek}, {"pop", f_pop},
		{"swap", f_swap}, {"add", f_sum},
		{"stack", f_stack}, {NULL, NULL}
	};
	opcode = strtok(content, " \t\n");

	if (opcode != NULL)
	{
		for (i = 0; opcomm[i].opcode != NULL; i++)
		{
			if (strcmp(opcomm[i].opcode, opcode) == 0)
			{
				if (strcmp(opcode, "push") == 0)
				{
					argument = strtok(NULL, " \t\n");
					if (argument == NULL)
					{
						fprintf(stderr, "L%d: usage: push integer\n", count);
						global_var->status = EXIT_FAILURE;
						break;
					}
					global_var->argument = argument;
				}
				opcomm[i].f(stack, count);
				return;
			}
		}
		if (opcomm[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
				count, opcode);
			global_var->status = EXIT_FAILURE;
		}
	}
}
