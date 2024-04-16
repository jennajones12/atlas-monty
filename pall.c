#include "monty.h"

/**
 * pall - Prints all the values on the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *s;

	(void)line_number;
	s = *stack;

	while (s != NULL)
	{
		printf("%d\n", s->n);
		s = s->next;
	}
}
