#include "monty.h"
#include <stdio.h>

/**
 * pint - check code.
 * @stack : variable
 * @line_number : variable
 * Return: check declaration
 */

void pint(stack_tt **stack, unsigned int line_number)
{
	int stack_len;

	stack_len = dlistint_len(*stack);
	if (stack_len == 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}

/**
 * pop - check code.
 * @stack : variable
 * @line_number : variable
 * Return: check declaration
 */

void pop(stack_tt **stack, unsigned int line_number)
{
	int stack_len;

	stack_len = dlistint_len(*stack);
	if (stack_len == 0)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		delete_dnodeint_at_index(stack, 0);
}

/**
 * swap - check code.
 * @stack : variable
 * @line_number : variable
 * Return: check declaration
 */

void swap(stack_tt **stack, unsigned int line_number)
{
	int a, b, stack_len;

	stack_len = dlistint_len(*stack);

	if (stack_len < 2)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	b = (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint(stack, a);
	add_dnodeint(stack, b);
}

/**
 * add - check code.
 * @stack : variable
 * @line_number : variable
 * Return: check declaration
 */
void add(stack_tt **stack, unsigned int line_number)
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
	add_dnodeint(stack, a + b);
}

/**
 * sub - check code.
 * @stack : variable
 * @line_number : variable
 * Return: check declaration
 */
void sub(stack_tt **stack, unsigned int line_number)
{
	int a, b, stack_len;

	stack_len = dlistint_len(*stack);

	if (stack_len < 2)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	b = (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint(stack, b - a);
}
