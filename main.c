#include "monty.h"
/*initialize the global pointer to NULL */
global_t *global_var = NULL;
/**
 *main - entry point to the monty interpreter
 *@argc: number of passed arguments
 *@argv: arguments passed to main
 *Return: On succes return 1
 */
int main(int argc, char *argv[])
{
	FILE *file;
	size_t size = 0;
	ssize_t readline;
	unsigned int count = 0;
	char *content = NULL;
	stack_t *stack = NULL;
	char *saveptr = NULL;
	char *token;

	global_var = malloc(sizeof(global_t));
	check_arguments(argc, argv);
	file = fopen(argv[1], "r");
	global_var->argument = NULL;

	while ((readline = getline(&content, &size, file)) != -1)
	{
		count++;
		if (content[readline - 1] == '\n')
			content[readline - 1] = '\0';

		if (content != NULL && content[0] != '#')
		{
			token = strtok_r(content, " \t", &saveptr);
			global_var->argument = strtok_r(NULL, " \t", &saveptr);
			execute(&stack, token, count);
		}
		free(content);
		content = NULL;
		size = 0;
	}
	fclose(file);
	free(global_var);
	free_stack(stack);
	free(content);

	return (EXIT_SUCCESS);
}
