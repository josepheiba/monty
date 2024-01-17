#include "monty.h"

/**
 * add - check code.
 * @stack : variable
 * @line_number : variable
 * Return: check declaration
 */
void divv(stack_tt **stack, unsigned int line_number)
{
	int a, b, stack_len;

	stack_len = dlistint_len(*stack);

	if (stack_len < 2)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	b = (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint(stack, b / a);
}
