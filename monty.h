#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char *line;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
};

typedef struct stack_s dlistint_t;
typedef struct stack_s stack_tt;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcoe
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_tt **stack, unsigned int line_number);
} instruction_t;

int not_int(char *s);
int argc_not_valid(int argc);
int file_open_fail(FILE **fd, char *argv_one);
void push(stack_tt **stack, unsigned int line_number);
void pall(stack_tt **stack, unsigned int line_number);
void pint(stack_tt **stack, unsigned int line_number);
void pop(stack_tt **stack, unsigned int line_number);
void swap(stack_tt **stack, unsigned int line_number);
void add(stack_tt **stack, unsigned int line_number);
void sub(stack_tt **stack, unsigned int line_number);
void nop(stack_tt **stack, unsigned int line_number);
void tokenize_and_continue(char *line, stack_tt **books, int ln);
void (*get_op_func(char *s, int ln))(stack_tt **stack, unsigned int l_n);

size_t print_dlistint(const dlistint_t *h);
size_t dlistint_len(const dlistint_t *h);
stack_tt *add_dnodeint(dlistint_t **head, const int n);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
void free_dlistint(dlistint_t *head);

#endif
