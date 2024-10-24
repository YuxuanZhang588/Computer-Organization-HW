#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

#define MAX_LEN 1000

/**
 * @brief This is the helper function that 
 * execute the command
 * 
 * @param parsed_arr 
 * @param bg 
 */
void execute(char** parsed_arr, int bg){
    pid_t pid;
    int ret;
    pid = fork();
    if (pid ==0){ // which means child
        // Check if we can execute the process
        ret = execvp(parsed_arr[0], parsed_arr);
        // Getting to this line means execvp failed
        printf("%s: command not found\n", parsed_arr[0]);
        int i=0;
        // Free the heap memory before exiting
        while (parsed_arr[i]!=NULL){
            free(parsed_arr[i]);
            i++;
        }
        free(parsed_arr[i]);
        free(parsed_arr);
        parsed_arr=NULL;
        exit(ret);
    }
    else if (pid > 0){ // which means parent
        // Wait only when bg=0
        if (bg == 0){
            // Null since we don't care about status
            waitpid(pid,NULL,0);
        }
        // If bg=1, we execute the process in the background 
        // without waiting, so just return to the main while loop
        return;
    }
    else{
        printf("Fork failed!\n");
        exit(1);
    }
}

/**
 * @brief The main method for the shell that 
 * prompts the user input and execute the command
 * 
 * @return 0
 */
int main(){
    // Reap the background process when exit; 
    signal(SIGCHLD, SIG_IGN);
    char commandLine[MAX_LEN];
    char** parsed_tokens;
    int bg;
    while (1){
        printf("catshell> ");
        fflush(stdout);
        if (fgets(commandLine, MAX_LEN, stdin)){
            parsed_tokens = parseCommand(commandLine, &bg);
            if (!strcmp( parsed_tokens[0], "exit")){
                // Free the allocated array before exiting
                int i=0;
                while (parsed_tokens[i]!=NULL){
                    free(parsed_tokens[i]);
                    i++;
                }
                free(parsed_tokens[i]);
                free(parsed_tokens);
                parsed_tokens=NULL;
                return 0;
            }
            // Execute the command
            execute(parsed_tokens, bg);
            // Free the allocated array
            int i=0;
            while (parsed_tokens[i]!=NULL){
                free(parsed_tokens[i]);
                i++;
            }
            free(parsed_tokens[i]);
            free(parsed_tokens);
            parsed_tokens=NULL;
        }
    }
    return 0;
}
