#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 Reads a line from `stream` into `*line_buf`
  growing `*buf_cap` as needed by getline
Returns the number of characters read, or -1 on error, EOF, or invalid args.
*/
ssize_t read_line(FILE *stream, char **line_buf, size_t *buf_cap)
{
  if (stream == NULL || line_buf == NULL || buf_cap == NULL)
  {
    return -1;
  }

  return getline(line_buf, buf_cap, stream);
}
/*
 * Replaces control and special whitespace characters (\n, \r, \t, \v, \f, \a, \b, etc.)
 * with spaces in-place while preserving the null terminator.
 */
char *sanatize_input(char *line)
{
  if (line == NULL)
  {
    return NULL;
  }

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

char **split_string()

int main(void)
{
  char *line = NULL;
  size_t capacity = 0;

  if (read_line(stdin, &line, &capacity) == -1)
  {
    printf("error reading line from stdin\n");
    free(line);
    return EXIT_FAILURE;
  }

  line = sanatize_input(line);
  if (line == NULL)
  {
    printf("error sanitizing input\n");
    free(line);
    return EXIT_FAILURE;
  }

  printf("line: %s\n", line);
  free(line);
  return EXIT_SUCCESS;
}
