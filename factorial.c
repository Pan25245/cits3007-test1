#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
//my program
long factorial(int n) {
  long result = 1;
  for (int i = n; i > 0; i--) {
    result *= i;
  }
  return result;
}

int main(int argc, char **argv) {
  argc--;
  argv++;

  if (argc != 1) {
    fprintf(stderr, "Error: expected 1 command-line argument (an INT), but got %d\n", argc);
    exit(1);
  }

  char *end;

  errno = 0;
  long n = strtol(argv[0], &end, 10);
  int res_errno = errno;

  if (*end != '\0') {
    fprintf(stderr, "Error: couldn't interpret '%s' as a number\n", argv[0]);
    exit(1);
  } else if (res_errno == ERANGE) {
    fprintf(stderr, "Error: '%s' is outside the range of numbers we can handle\n", argv[0]);
    exit(1);
  } else if (n > INT_MAX) {
    fprintf(stderr, "Error: '%s' is too big to fit in an int\n", argv[0]);
    exit(1);
  } else if (n < 0) {
    fprintf(stderr, "Error: invalid value %ld: factorial can only be calculated for non-negative numbers\n", n);
    exit(1);
  }

  int nn = (int) n; // Use int instead of short here
  long result = factorial(nn);
  printf("factorial(%d) is %ld\n", nn, result);
}
