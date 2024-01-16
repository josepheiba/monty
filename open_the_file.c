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
		return (1);
	else
		return (0);
}
