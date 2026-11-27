#define _POSIX_C_SOURCE 200809L

#include "tokens.h"

#include <stdlib.h>
#include <string.h>

char **split_tokens(char *line, const char *delim)
{
  if (line == NULL || delim == NULL)
  {
    return NULL;
  }

  /* Start with a 1-slot NULL-terminated array (handles blank lines cleanly) */
  char **words = malloc(sizeof(char *));
  if (words == NULL)
  {
    return NULL;
  }
  words[0] = NULL;

  /* TODO: replace strtok_r with a lexer when adding quotes, escapes, or operators (|, <, >) */
  char *saveptr = NULL;
  char *token = strtok_r(line, delim, &saveptr);
  size_t word_count = 0;

  while (token != NULL)
  {
    /* Duplicate the token onto the heap so words[] owns its own strings */
    char *word_copy = strdup(token);
    if (word_copy == NULL)
    {
      free_tokens(words);
      return NULL;
    }

    /* Grow array by 1 slot (+1 for the trailing NULL) using a temp pointer */
    char **resized = realloc(words, sizeof(char *) * (word_count + 2));
    if (resized == NULL)
    {
      free(word_copy);
      free_tokens(words);
      return NULL;
    }

    words = resized;
    words[word_count] = word_copy;
    word_count++;
    words[word_count] = NULL;

    token = strtok_r(NULL, delim, &saveptr);
  }

  return words;
}

void free_tokens(char **tokens)
{
  if (tokens == NULL)
  {
    return;
  }

  for (size_t i = 0; tokens[i] != NULL; i++)
  {
    free(tokens[i]);
  }

  free(tokens);
}
