#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
  char *comand;
  char input[1024];
  while (1) {
    printf("$ ");
    if (!fgets(input, 1024, stdin)) break;
    if ((comand = strtok(input, " \t\r\n"))) {
        if (strcmp(comand, "quit") == 0) break;
        else system(input);
    }
  }
  return 0;
}