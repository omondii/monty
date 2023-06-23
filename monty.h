#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

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

/**
 *struct comm_s - contains args, file, content and line content passed
 to the program. Used by monty
 *@args: arguments passed to main
 *@file: file to process
 *@content: contents of the file being processed
 *@lineno: line number being processed
 */
typedef struct global_s
{
	char *argument;
} global_t;
extern global_t *global_var;

void f_stack(stack_t **head, unsigned int count);
ssize_t getstdin(char **lineptr, int file);
void f_push(stack_t **head, unsigned int n);
void f_display(stack_t **head, unsigned int count);
void f_peek(stack_t **head, unsigned int n);
void f_pop(stack_t **head, unsigned int n);
void f_swap(stack_t **head, unsigned int n);
void f_sum(stack_t **head, unsigned int n);
void f_nop(stack_t **head, unsigned int count);
void free_stack(stack_t *head);
void execute(stack_t **head, char *content, unsigned int count);
#endif
