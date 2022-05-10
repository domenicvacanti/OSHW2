#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char * environ[]){
    int i;
    printf("\n");
    for (i = 0; environ[i] != NULL; i++)
        printf("%s\n", environ[i]);
    return 0;
}