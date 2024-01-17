#include "monty.h"

/**
 * main - check code.
 * @argc : variable
 * @argv : variable
 * Return: check declaration
 */

int main(int argc, char **argv)
{
	int ln;
	FILE *fd;
	size_t len = 0;
	stack_tt *stack = NULL;

	ln = 1;
	line = NULL;
	argc_not_valid(argc);
	file_open_fail(&fd, argv[1]);

	while (getline(&line, &len, fd) != -1)
	{
		tokenize_and_continue(line, &stack, ln);
		ln++;
	}
	free(line);
	free_dlistint(stack);
	fclose(fd);
	return (0);
}

/**
 * tokenize_and_continue - check code.
 * @line : variable
 * @stack : variable
 * @ln : variable
 * Return: check declaration
 */

void tokenize_and_continue(char *line, stack_tt **stack, int ln)
{
	char *token1;

	token1 = strtok(line, " \n\t");

	if (token1 != NULL)
		get_op_func(token1, ln)(stack, ln);
}

/**
 * get_op_func - check code.
 * @s : variable
 * @line_number : variable
 * Return: check declaration
 */

void (*get_op_func(char *s, int ln))(stack_tt **stack,
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
		{"nop", nop},
		{"ok", nop}
	};
	int i;

	i = 0;
	while (i < 11)
	{
		if (!strcmp(s, (ops + i)->opcode))
			return ((ops + i)->f);
		i++;
	}
	dprintf(2, "L%d: unknown instruction %s\n", ln, s);
	exit(EXIT_FAILURE);
	return ((ops + i)->f);
}
