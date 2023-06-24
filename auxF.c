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

	if (argc != 2 || file == NULL)
	{
		fprintf(stderr, "Error: ");
		if (argc != 2)
			fprintf(stderr, "USAGE: monty file\n");
		else
			fprintf(stderr, "Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}

int is_digit(char *argument)
{
	int i;
	if (argument[0] == '\0')
		return(0);

	i = 0;
	while (argument[i] != '\0')
	{
		if (isdigit(argument[i]))
		{
			i++;
			continue;
		}
		return (0);
	}
	return (1);
}

int ispositive(char *argument)
{
	int i;

	i = 0;
	while (argument[i] != '\0')
	{
		if ((argument[i] <= '0'))
		{
			i++;
			continue;
		}
		break;
	}
	if (argument[i] != '\0')
	{
		fprintf(stderr, "Error: Non-positive integer detected\n");
		exit(EXIT_FAILURE);
	}
	return (1);
}
