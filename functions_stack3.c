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
		print_err2(8, line_num, "mul");

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

		print_err2(8, line_num, "mod");


	if ((*stack)->n == 0)
		print_err2(9, line_num);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
* print_char - print char
* @stack: list of nodes
* @line_num: line number
*/

void print_char(stack_t **stack, unsigned int line_num)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		print_err2(11, line_num);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		print_err2(10, line_num);
	printf("%c\n", ascii);
}

/**
* print_str - print string
* @stack: list of nodes
* @line_num: line number
*/

void print_str(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}
