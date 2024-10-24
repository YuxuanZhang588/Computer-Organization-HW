#include <stdio.h>
#include "parser.h"

int main(){
    char line[1000];
    char** tokens;
    int bg;
    while(fgets(line, 1000, stdin)){
        tokens = parseCommand(line, &bg);
        printf("bg = %d\n", bg);
        fflush(stdout);
        for(int i=0; tokens[i] != NULL; i++){
            printf("Token %d = %s", i, tokens[i]);
            fflush(stdout);
        }
    }
}