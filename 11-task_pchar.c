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

/**
 * pstr - check code.
 * @stack : variable
 * @line_number : variable
 * Return: check declaration
 */

void pstr(stack_tt **stack, unsigned int line_number)
{
	int ch;
	char character;
	stack_tt *head;

	(void) line_number;
	head = *stack;
	while (head != NULL && head->n != 0 && head->n >= 32 && head->n <= 126)
	{
		ch = (head)->n;
		character = ch;
		printf("%c", character);
		head = head->next;
	}
	printf("\n");
}

/**
 * rotl - check code.
 * @stack : variable
 * @line_number : variable
 * Return: check declaration
 */

void rotl(stack_tt **stack, unsigned int line_number)
{
	int stack_len, a;

	(void) line_number;
	stack_len = dlistint_len(*stack);
	if (stack_len < 2)
	{
		return;
	}
	a = (get_dnodeint_at_index(*stack, 0))->n;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint_end(stack, a);
}
