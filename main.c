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
	char *montyfile = NULL;
	FILE *file = NULL;
	int status = EXIT_SUCCESS;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		montyfile = argv[1];
		file = fopen(montyfile, "r");
		if (file == NULL)
		{
			status = EXIT_FAILURE;
		}
		else
		{
			global_var = malloc(sizeof(global_t));
			if (global_var == NULL)
			{
				fprintf(stderr, "Error: memory allocation failed\n");
				exit(EXIT_FAILURE);
			}
			status = readfile(file);
			fclose(file);
			free(global_var);
		}
	}
	return (status);
}
