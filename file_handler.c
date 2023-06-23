#include "monty.h"

/**
* parse_line - open file
* @file_name: string of name
*/

void parse_line(char *file_name)
{
	FILE *fd;

	if (file_name == NULL)
		print_err(2, file_name);
	if (access(file_name, R_OK) == -1)
		print_err(2, file_name);
	fd = fopen(file_name, "r");
	if (fd == NULL)
		print_err(2, file_name);
	read_file(fd);
	fclose(fd);
}

/**
* read_file - read file lines
* @fd: file detector
*/

void read_file(FILE *fd)
{
	char *line_str;
	size_t len;
	int n_line, fmt;

	line_str = NULL;
	n_line = 1;

	while (getline(&line_str, &len, fd) != -1)
	{
		fmt = tokenize_line(line_str, n_line, fmt);
		n_line++;
	}
	free(line_str);
}

/**
* tokenize_line - tokenize the line
* @line_str: line string
* @n_line: line number
* @fmt: format queue or stack
* Return: return 1 if queue or 0 if stack
*/

int tokenize_line(char *line_str, int n_line, int fmt)
{
	const char *delim = " \n\t\a\b";
	char *opcode;
	char *value;

	if (line_str == NULL)
		print_err(3);
	opcode = strtok(line_str, delim);
	if (opcode == NULL)
		return (fmt);
	value = strtok(NULL, delim);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	else if (strcmp(opcode, "stack") == 0)
		return (0);
	fun_finder(opcode, value, n_line, fmt);
	return (fmt);
}

/**
* fun_finder - function finder from list
* @opcode: opcode
* @value: value
* @n_line: line number
* @fmt: format queue or stack
*/

void fun_finder(char *opcode, char *value, int n_line, int fmt)
{
	int flag = 1, i = 0;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"nop", nop_nothing},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{NULL, NULL}
	};
	if (opcode[0] == '#')
		return;
	while (func_list[i].opcode != NULL)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			fun_call(func_list[i].f, opcode, value, n_line, fmt);
			flag = 0;
		}
		i++;
	}
	if (flag == 1)
		print_err(3, n_line, opcode);
}

/**
* fun_call - function call
* @fun_op: opcode function
* @op: opcode
* @val: value
* @n_line: line number
* @fmt: format queue or stack
*/

void fun_call(opcode_fun fun_op, char *op, char *val, int n_line, int fmt)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			print_err(5, n_line);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				print_err(5, n_line);
		}
		node = create_node(atoi(val) * flag);
		if (fmt == 0)
			fun_op(&node, n_line);
		if (fmt == 1)
			add_to_queue(&node, n_line);
	}
	else
		fun_op(&head, n_line);
}
