#include "monty.h"
#include <string.h>

/**
 * main - check code.
 * @argc : variable
 * @argv : variable
 * Return: check declaration
 */

int main(int argc, char **argv)
{
	int ln, lifo;
	FILE *fd;
	size_t len = 0;
	stack_tt *stack = NULL;

	ln = lifo = 1;
	line = NULL;
	argc_not_valid(argc);
	file_open_fail(&fd, argv[1]);

	while (getline(&line, &len, fd) != -1)
	{
		tokenize_and_continue(&stack, ln, &lifo);
		ln++;
	}
	free(line);
	free_dlistint(stack);
	fclose(fd);
	return (0);
}

/**
 * tokenize_and_continue - check code.
 * @stack : variable
 * @ln : variable
 * @lifo : variable
 * Return: check declaration
 */

void tokenize_and_continue(stack_tt **stack, int ln, int *lifo)
{
	char *token1;

	token1 = strtok(line, " \n\t");

	if (token1 != NULL)
	{
		if (!strcmp(token1, "stack"))
		{
			*lifo = 1;
			return;
		}
		else if (!strcmp(token1, "queue"))
		{
			*lifo = 0;
			return;
		}
	}

	if (token1 != NULL && token1[0] != '#')
		get_op_func(token1, ln, lifo)(stack, ln);
}

/**
 * get_op_func - check code.
 * @s : variable
 * @ln : variable
 * @line_number : variable
 * Return: check declaration
 */

void (*get_op_func(char *s, int ln, int *lifo))(stack_tt **stack,
			unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divv},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"nop", nop},
		{"ok", nop}
	};
	int i;

	if (*lifo == 0)
	{
		(ops + 0)->f = push2;
	}

	i = 0;
	while (i < 15)
	{
		if (!strcmp(s, (ops + i)->opcode))
			return ((ops + i)->f);
		i++;
	}
	dprintf(2, "L%d: unknown instruction %s\n", ln, s);
	exit(EXIT_FAILURE);
	return ((ops + i)->f);
}
