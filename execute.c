#include "monty.h"
comm_t com = {NULL, NULL, NULL, 0};
/**
 *execute - parses the entered command, and compares each token to
 *to moncmd[]
 *@stack: pointer to a stack implementation
 *@content: arguments to parse and compare
 *@count: line number being executed
 *@file: pointer to the file being operatd on
 *Return: on success (0), on fail (1)
 */
int execute(stack_t **stack, char *content, unsigned int count, FILE *file)
{
	char *token;
	unsigned int i;

	instruction_t moncmd[] = {
		{"push", f_push}, {"pall", f_display},
		{"pint", f_peek}, {"pop", f_pop},
		{"swap", f_swap}, {"add", f_sum},
		{NULL, NULL}
	};

	token = strtok(content, " \t\n");
	if (token && token[0] == '#')
		return (0);

	com.args = strtok(NULL, "\n\t");

	i = 0;
	while (moncmd[i].opcode && token)
	{
		if (strcmp(token, moncmd[i].opcode) == 0)
		{
			moncmd[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (token && moncmd[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instructions %s\n", count, token);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (0);
}
