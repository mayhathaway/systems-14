#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args( char * line ) {
  char *args[128];
  char *g = line;
  int i = 0;
  while (g) {
    args[i] = strsep(&g, " ");
    i++;
  }
  return args;
}

int main() {
  char cmd[] = "touch test.txt";
  char **args = parse_args(cmd);
  execvp(args[0], args);
  return 0;
}
