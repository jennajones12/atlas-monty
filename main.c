#include "monty.h"

int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
	    char *opcode = strtok(line, " \n");
	    if (opcode == NULL || opcode[0] == '#')
		    continue;
       
	line_number++;

	if (strcmp(opcode, "push") == 0)
		push(&stack, line_number);
	else if (strcmp(opcode, "pall") == 0)
		pall(&stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
    }

    free(line);
    fclose(file);
    return (0);
}
