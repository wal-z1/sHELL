#define _POSIX_C_SOURCE 200809L

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

  printf("line: %s\n", line);
  free(line);
  return EXIT_SUCCESS;
}
