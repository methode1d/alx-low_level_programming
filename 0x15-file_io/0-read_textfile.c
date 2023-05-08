#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - This will read a text file then prints it to POSIX stdout.
 * @filename: Pointer and name of the file.
 * @letters: Number of letters the
 *           function must read and print.
 *
 * Return: If a function fails or filename is NULL - 0.
 *         O/w - the actual number of bytes the function can be read and printed as well.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, r, w;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	o = open(filename, O_RDONLY);
	r = read(o, buffer, letters);
	w = write(STDOUT_FILENO, buffer, r);

	if (o == -1 || r == -1 || w == -1 || w != r)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(o);

	return (w);
}
