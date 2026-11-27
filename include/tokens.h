#ifndef TOKENS_H
#define TOKENS_H

/* Splits `line` by any character in `delim` into a NULL-terminated heap array
   of duplicated tokens. Returns NULL on invalid args or allocation failure,
   and [NULL] on blank input. */
char **split_tokens(char *line, const char *delim);

/* Frees a NULL-terminated array of heap-allocated strings. */
void free_tokens(char **tokens);

#endif
