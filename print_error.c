#include "shell.h"

/**
 * _itoa - converts int to string
 * @value: the int to convert
 * Return: formatted string
 */
char *_itoa(int value)
{
	char string[9], *final_string;
	int size = 1, pos = 0, copy = value, mul = 1;

	while (copy > 10)
	{
		copy /= 10;
		mul *= 10;
		size += 1;
	}
	while (size > 0)
	{
		if ((value / mul) < 10)
			string[pos] = (value / mul) + '0';
		else
			string[pos] = ((value / mul) % 10) + '0';
		size--;
		pos++;
		mul /= 10;
	}
	string[pos] = '\0';
	final_string = string;
	return (final_string);
}

/**
 * print_error - prints formatted error message
 * @av: list of arguments
 * @cmd: list of commands
 * @cound: current input line
 * Return: nothing
 */
void print_error(char *av, int count, char *cmd)
{
	char delim[3] = ": ", nf[10] = "not found\n", buffer[1024];

	strcpy(buffer, av);
	strcat(buffer, delim);
	strcat(buffer, _itoa(count));
	strcat(buffer, delim);
	strcat(buffer, cmd);
	strcat(buffer, delim);
	strcat(buffer, nf);
	write(STDERR_FILENO, buffer, _strlen(buffer) - 1);
}