
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  char *buf;
  buf = malloc(1<<31); // allocate a large buffer
  printf("type some text and hit 'return':\n");
  fgets(buf, 1024, stdin); // read 1024 chars into buf
  printf("\n%s\n\n", buf); // print what was entered
  free(buf);
  return 0;
}
