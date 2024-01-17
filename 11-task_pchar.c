#include "monty.h"

/**
 * pchar - check code.
 * @stack : variable
 * @line_number : variable
 * Return: check declaration
 */

void pchar(stack_tt **stack, unsigned int line_number)
{
	int stack_len, ch;
	char character;

	stack_len = dlistint_len(*stack);
	if (stack_len == 0)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	ch = (*stack)->n;
	if (ch < 32 || ch > 126)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	character = ch;
	printf("%c\n", character);
}
