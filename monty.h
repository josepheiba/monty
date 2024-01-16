#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int argc_not_valid(int argc);
int file_open_fail(FILE **fd, char *argv_one);
void push(stack_t **stack, unsigned int line_number);
void done(stack_t **stack, unsigned int line_number);
void tokenize_and_continue(char *line, stack_t **books);
void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number);

#endif
