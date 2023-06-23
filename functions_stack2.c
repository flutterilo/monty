#include "monty.h"

/**
* swap_nodes - swap values of top node
* @stack: list of nodes
* @line_num: line number
*/

void swap_nodes(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_err2(8, line_num, "swap");

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *stack;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
* add_nodes - add nodes in to of stack
* @stack: list of nodes
* @line_num: line number
*/

void add_nodes(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_err2(8, line_num, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
* nop_nothing - does nothing
* @stack: list of nodes
* @line_num: line number
*/

void nop_nothing(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}

/**
* sub_nodes - subtract the top element of stack
* @stack: list of nodes
* @line_num: line number
*/

void sub_nodes(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		print_err2(8, line_num, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
* div_nodes - divide the top two elements of the stack.
* @stack: list of nodes
* @line_num: line number
*/

void div_nodes(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_err2(8, line_num, "div");

	if ((*stack)->n == 0)
		print_err2(9, line_num);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
