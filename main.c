#include "monty.h"
comm_t com = {NULL, NULL, NULL, 0};
/**
 * main - entry point into monty interpreter
 *@argc: total number of passed arguments
 *@argv: array containing passed args
 *Return:On success(1), on fail(0)
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	com.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		com.content = content;
		count++;
		if (read_line > 0)
		{
			execute(&stack, content, count, file);
		}
	}
	free_stack(stack);
	return (0);
}
