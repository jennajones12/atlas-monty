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
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        char *opcode = strtok(line, " \n\t");
        char *arg = strtok(NULL, " \n\t");

        line_number++;

        if (opcode && strcmp(opcode, "push") == 0)
        {
            if (arg && isdigit(*arg))
                push(&stack, line_number, atoi(arg));
            else
            {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                free(line);
                fclose(file);
                free_stack(stack);
                exit(EXIT_FAILURE);
            }
        }
        else if (opcode && strcmp(opcode, "pall") == 0)
        {
            pall(&stack, line_number);
        }
    }

    free(line);
    fclose(file);
    free_stack(stack);
    return (0);
}
