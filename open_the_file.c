#include "monty.h"

/**
 * open_the_file - check code.
 * @argc : variable
 * Return: check declaration
 */

int file_open_fail(FILE **fd, char *argv_one)
{
	*fd = fopen(argv_one, "r");
	if (*fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv_one);
		exit (EXIT_FAILURE);
	}
	else
		return (0);
}
