#ifndef INPUT_H
#define INPUT_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <sys/types.h>

/* Reads a line from stream into *buf, growing *cap as needed. */
ssize_t read_line(FILE *stream, char **buf, size_t *cap);

/* Replaces control/whitespace chars with spaces in-place. */
char *sanitize_input(char *line);

#endif
