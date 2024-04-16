#include "monty.h"

/**
 * main - Entry point of the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		char *opcode;
		char *argument;

		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || *opcode == '#')
			continue;

		argument = strtok(NULL, " \t\n");
		if (strcmp(opcode, "push") == 0 && argument == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(file);
			free(line);
			return (EXIT_FAILURE);
		}

		if (strcmp(opcode, "push") == 0)
		{
			push(&stack, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			fclose(file);
			free(line);
			return (EXIT_FAILURE);
		}
	}

	fclose(file);
	if (line)
		free(line);

	return (EXIT_SUCCESS);

