#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

/**
 * @brief This function parse a command line 
 * to a tokens array
 * 
 * @param cmdLine the command that user inputs
 * @param bg whether foreground orbackground 
 * @return the tokens array
 */
char** parseCommand(const char* cmdLine, int* bg){
    // Declare the tokens first 
    char** tokens;
    char* copy = strdup(cmdLine);
    // run through the copy to find the &
    int find_bg=0;
    while (copy[find_bg]!='\0' && copy[find_bg]!='&'){
        find_bg++;
    }
    // If we find an &
    if (copy[find_bg]=='&'){
        *bg = 1;
    }
    // If there is no &, set the find_bg to -1.
    else {
        *bg = 0;
    }
    int num_words=0;
    int len_token=0;
    for (int i=0; i<find_bg; i++){
        // If it's not a white space
        if (isspace(copy[i]) == 0){
            len_token++;
        }
        // If it is a space
        else {
            // !=0 indicates we read a word
            if (len_token!=0){
                num_words++;
                len_token=0;
            }
        }
    }
    if (len_token !=0){
        num_words++;
    }
    tokens = malloc(sizeof(char*) * (num_words+1));
    if (tokens==NULL){
        printf("Malloc failed!");
        exit(1);
    }
    // Initilize all tokens[i] to NULL;
    for (int i=0; i<=num_words; i++){
        tokens[i]=NULL;
    }
    // Using for loop to fill the words
    int num_token=0;
    len_token=0;
    for (int i=0; i<find_bg; i++){
        // if it's not a white space
        if (isspace(copy[i]) == 0){
            len_token++;
        }
        // If it is a space
        else {
            // !=9 indicates we read a word
            if (len_token!=0){
                tokens[num_token]=malloc(sizeof(char) * (len_token+1));
                if (tokens[num_token]==NULL){
                    printf("Malloc failed!");
                    exit(1);
                }
                strncpy(tokens[num_token], copy+i-len_token,len_token);
                tokens[num_token][len_token]='\0';
                num_token++;
                len_token=0;
            }
        }
    }
    // If there is no space after the last word, 
    // we manually adjust it
    if (len_token !=0){
        tokens[num_token]=malloc(sizeof(char) * (len_token+1));
        if (tokens[num_token]==NULL){
            printf("Malloc failed!");
            exit(1);
        }
        strncpy(tokens[num_token], copy+find_bg-len_token,len_token);
        tokens[num_token][len_token]='\0';
        num_token++;
    }
    free(copy);
    copy=NULL;
    return tokens;
}