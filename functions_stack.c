#include "monty.h"

/**
* add_to_stack - function to add stack
* @new_node: new node
* @ln_num: line
*/

void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned
									int ln_num)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
* add_to_queue - add to queue
* @new_node: new node
* @ln_num: line number
*/

void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned
									int ln_num)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}

/**
* print_stack - print all n node in stack
* @stack: list of nodes
* @line_number: line number
*/

void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
* print_top - print the top of stack
* @stack: list of nodes
* @line_number: line number
*/

void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		print_err(6, line_number);
	printf("%d\n", (*stack)->n);
}

/**
* pop_top - pop the top of stack
* @stack: list of nodes
* @line_number: line number
*/

void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		print_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
