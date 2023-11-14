#include <stdio.h>
#include <stdlib.h>

/**
 * main - adds numbers
 *
 * av: argument vector
 *
 * ac: argument count
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	printf("argv content is argv[]\n");
	while (*av != NULL)
	{
		printf("argv = %s\n", *av);
		av++;
	}
	return (0);
}
