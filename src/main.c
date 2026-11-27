#define _POSIX_C_SOURCE 200809L

#include "input.h"
#include "tokens.h"

#include <stdio.h>
#include <stdlib.h>

static char *line = NULL;   /* raw input buffer, managed by getline */
static size_t capacity = 0; /* allocated capacity of line buffer    */
static int running = 1;     /* loop control: 1 = running, 0 = exit  */

int main(void)
{
  /* TODO: initialize shell signal handlers (see include/signals.h) */

  while (running)
  {
    /* Prompt the user */
    printf("sHELL> ");
    fflush(stdout);

    /* Read a line from stdin */
    if (read_line(stdin, &line, &capacity) == -1)
    {
      if (ferror(stdin))
      {
        perror("error: failed to read from stdin");
        free(line);
        return EXIT_FAILURE;
      }
      break;
    }

    /* Normalize whitespace and control characters */
    if (sanitize_input(line) == NULL)
    {
      fprintf(stderr, "error: failed to sanitize input\n");
      free(line);
      return EXIT_FAILURE;
    }

    /* Split the line into a NULL-terminated array of tokens */
    char **words = split_tokens(line, " ");
    if (words == NULL)
    {
      fprintf(stderr, "error: failed to tokenize input\n");
      free(line);
      return EXIT_FAILURE;
    }

    /* Execute command (skip if user only pressed Enter / spaces) */
    if (words[0] != NULL)
    {
      /* TODO: check builtins first (builtins.h), then execute external command (exec.h) */
      for (size_t i = 0; words[i] != NULL; i++)
      {
        printf("token[%zu]: %s\n", i, words[i]);
      }
    }

    /* Clean up tokens before the next prompt */
    free_tokens(words);
  }

  printf("\n");
  free(line);
  return EXIT_SUCCESS;
}
