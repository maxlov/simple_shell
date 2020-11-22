#include "shell.h"

/**
 * free2d - frees 2d array
 * @lines: 2d array
 * Return: nothing
 */
void free2d(char **lines)
{
	int i = 0;

	while (lines[i] != NULL)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}
