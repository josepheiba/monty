#include "monty.h"

/**
 * argc_not_valid - check code.
 * @argc : variable
 * Return: check declaration
 */

int argc_not_valid(int argc)
{
	if (argc == 2)
		return (0);
	dprintf(2, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
