#include "monty.h"

/**
 * file_open_fail - check code.
 * @fd : variable
 * @argv_one : variable
 * Return: check declaration
 */

int file_open_fail(FILE **fd, char *argv_one)
{
	*fd = fopen(argv_one, "r");
	if (*fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv_one);
		exit(EXIT_FAILURE);
	}
	else
		return (0);
}
