#include "monty.h"

/**
* mul_nodes - multiply top of elements
* @stack: list of nodes
* @line_num: line number
*/

void mul_nodes(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_err(8, line_num, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
* mod_nodes - modolu top of elements
* @stack: list of nodes
* @line_num: line number
*/

void mod_nodes(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		print_err(8, line_num, "mod");


	if ((*stack)->n == 0)
		print_err(9, line_num);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
