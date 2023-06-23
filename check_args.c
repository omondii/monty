#include "monty.h"
/**
 *check_arguments -check the argmunents passed if they meet monty usage
 *@argc: number of passed args
 *@argv: arguments passed
 */
void check_arguments(int argc, char *argv[])
{
	FILE *file;

	file = fopen(argv[1], "r");

	if (argc != 2 || !(file))
	{
		fprintf(stderr, "Error: ");
		if (argc != 2)
			fprintf(stderr, "USAGE: monty file\n");
		else
			fprintf(stderr, "Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}
