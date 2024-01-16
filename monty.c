#include "monty.h"

/**
 * main - check code.
 * @argc : variable
 * @argv : variable
 * Return: check declaration
 */

int main(int argc, char **argv)
{
	FILE *fd;
	char *line = NULL;
	size_t len = 0;
	stack_t *books;

	if (argc_not_valid(argc))
		return (-1);
	if (file_open_fail(&fd, argv[1]))
		return (-1);
	while (getline(&line, &len, fd) != -1)
	{
		tokenize_and_continue(line, &books);
	}
	return (0);
}

/**
 * get_op_func - check code.
 * @s : variable
 * Return: check declaration
 */

void tokenize_and_continue(char *line, stack_t **books)
{
	char *token1;
	char *token2;

	token1 = strtok(line, " \n");
	token2 = strtok(NULL, " \n");
	get_op_func(token1)(books, atoi(token2));
}

/**
 * get_op_func - check code.
 * @s : variable
 * Return: check declaration
 */

void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"ok", done}
	};
	int i;

	i = 0;
	while (i < 1)
	{
		if (!strcmp(s, (ops + i)->opcode))
			return ((ops + i)->f);
		i++;
	}
	return ((ops + i)->f);
}
