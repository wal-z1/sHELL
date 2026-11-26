#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv[])
{
  char *line = NULL;
  size_t len = 0;

  if (argc < 2)
  {
    printf("command less then two arguments", argv[0]);
    return 1;
  }
  read_line_stdin_getline(stdin, &line, &len);
}

int read_line_stdin_getline(FILE *fp, char **lineptr, size_t *n)
{
  int nread;
  if (fp == NULL || lineptr == NULL || n == NULL)
  {
    return -1;
  }
  if (nread = getline(lineptr, n, fp) == -1)
  {
    return -1;
  }
  return nread;
}