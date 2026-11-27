#define _POSIX_C_SOURCE 200809L

#include "input.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

ssize_t read_line(FILE *stream, char **buf, size_t *cap)
{
  if (stream == NULL || buf == NULL || cap == NULL)
  {
    return -1;
  }

  return getline(buf, cap, stream);
}

char *sanitize_input(char *line)
{
  if (line == NULL)
  {
    return NULL;
  }

  /* TODO: preserve characters inside quotes ('...' / "...") when quote support is added */
  for (size_t i = 0; line[i] != '\0'; i++)
  {
    unsigned char ch = (unsigned char)line[i];
    if (iscntrl(ch) || isspace(ch))
    {
      line[i] = ' ';
    }
  }

  return line;
}
