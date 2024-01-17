#include "monty.h"
#include <ctype.h>

/**
 * push - check code.
 * @stack : variable
 * @line_number : variable
 * Return: check declaration
 */
void push(stack_tt **stack, unsigned int line_number)
{
	char *token2;
	int number;

	token2 = strtok(NULL, " \n");
	if (token2 != NULL)
	{
		if(not_int(token2))
		{
			dprintf(2, "L%d: usage: push integer\n", line_number);
			exit (EXIT_FAILURE);
		}
		else
		{
			number = atoi(token2);
			add_dnodeint(stack, number);		
		}
	}
	else
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit (EXIT_FAILURE);
	}
}

/**
 * pall - check code.
 * @stack : variable
 * @line_number : variable
 * Return: check declaration
 */
void pall(stack_tt **stack, unsigned int line_number)
{
	(void) line_number;
	print_dlistint(*stack);
}

/**
 * nop - check code.
 * @stack : variable
 * @line_number : variable
 * Return: check declaration
 */
void nop(stack_tt **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * not_int - check code
 * @s: input
 * Return: check function declaration
 */

int not_int(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '-' && i == 0)
			i++;
		if (s[i] >= 58 || s[i] <= 47)
			return (1);
		i++;
	}
	return (0);
}
