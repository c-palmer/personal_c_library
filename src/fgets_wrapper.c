#include <stdio.h>
#include <string.h>

/* add features:
 *   figure out a way to not have two trailing \0s while still capturing \n
 */

/* only modifies behavior of fgets when stream == stdin
 * if input from stdin is too long, function will prompt user for input again
 * string is too long if \n is not captured
 * function clears all chars from stdin before prompting again
 * finally, function replaces \n with \0 before returning successfully
 */
char *fgets_wrapper(char *str, int n, FILE *stream, char *prompt)
{
  if (stream != stdin)
    return fgets(str, n, stream);

  while (1)
  {
    printf("%s", prompt);
    char *return_value = fgets(str, n, stdin);

    char *newline_found = memchr(str, '\n', n);
    if (newline_found != NULL)
    {
      // memchr returns a pointer to the first occurance of '\n'
      newline_found[0] = '\0';
      return return_value;
    }

    printf("input too long, please try again.\n");

    // clear stdin
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
  } 
}
