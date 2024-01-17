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
	int stack_len, ch;
	char character;
	stack_tt *head;

	(void) line_number;
	stack_len = dlistint_len(*stack);
	if (stack_len == 0)
	{
		printf("\n");
	}
	else
	{
		head = *stack;
		ch = (head)->n;
		while ((ch < 32 || ch > 126) && ch != 0 && head != NULL)
		{
			character = ch;
			printf("%c", character);
			head = head->next;
		}
		printf("\n");
	}
}
