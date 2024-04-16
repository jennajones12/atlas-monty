#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty file
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \n");
	stack_t *new_node;

	if (arg == NULL || !is_numeric(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
