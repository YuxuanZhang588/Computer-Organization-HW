/* HW1 Assembler (for the HW4 CPU's assembly language).
 *
 * Time spent: 5 hours
 *
 * Authors: Yuxuan Zhang
 * 
 * Description: This function translates assembly code instruction into
 * its opcode in hex.
 * 
*/

#include <stdio.h>
#include <string.h> // strcmp defined here
#include <stdlib.h> // exit defined here

#define ASCII_ZERO 48
#define ASCII_NINE 57

/* Reads and translates the input file to an output file.

   Parameters:
       argc - the number of arguments that we are given in the command line.
       argv[] - an array that contains the command line arguments.

   Returns: 0 if the translation is successful or exit with error code 1 if 
            unsuccessful.       
*/
int main(int argc, char* argv[]){
    if(argc != 3){ // check for the right number of arguments
        printf("usage: ./assembler infile outfile\n");
        exit(1);
    }
    FILE* infile = fopen(argv[1], "r");
    if(infile == NULL){ // check if the source file is valid
        printf("Error: unable to read source file: my_code.assembly.\n");
        exit(1);
    }
    FILE* outfile = fopen(argv[2], "w");
    if(outfile == NULL){ // check if the output file is valid
        printf("Error: unable to write output file: my_code.binary.\n");
        exit(1);
    }

    fputs("v2.0 raw\n", outfile);
    char token[10];
    
    while(fscanf(infile, "%s", token) != EOF){ // iterate through each string
        if(strcmp(token, "INPUT") == 0){ // compare the tokens with instructions
            fputs("04", outfile);
        }
        else if(strcmp(token, "OUTPUT") == 0){
            fputs("07", outfile);
        }
        else if(strcmp(token, "INC") == 0){
            fputs("14", outfile);
        }
        else if(strcmp(token, "MOV") == 0){
            fputs("17", outfile);
        }
        else if(strcmp(token, "ADD") == 0){
            fputs("1a", outfile);
        }
        else if(strcmp(token, "HALT") == 0){
            fputs("1d", outfile);
        }
        else if(strcmp(token, "NOP") == 0){
            fputs("1f", outfile);
        }
        else if(strcmp(token, "JMP") == 0){
            fscanf(infile, "%s", token);
            if(token[2] != 0){ // check if the following hex number has no more 
                               // than two digits
                printf("Error: invalid token: juMP.\n");
                exit(1);
            }
            else if(((ASCII_ZERO <= token[0]) && (token[0] <= ASCII_NINE)) || 
            (('a' <= token[0]) && (token[0] <= 'f'))){
                if(((ASCII_ZERO <= token[1]) && (token[1] <= ASCII_NINE)) || 
                (('a' <= token[1]) &&(token[1] <= 'f'))){ // check if the two 
                    fputs("0a\n", outfile);          // numbers are hex numbers
                    fprintf(outfile, "%s", token);
                }
            }   
        }
        else if(strcmp(token, "LOAD") == 0){
            fscanf(infile, "%s", token);
            if(token[2]!=0){
                printf("Error: invalid token: juMP.\n");
                exit(1);
            }
            if(((ASCII_ZERO <= token[0]) && (token[0] <= ASCII_NINE)) || 
            (('a' <= token[0]) && (token[0] <= 'f'))){
                if(((ASCII_ZERO <= token[1]) && (token[1] <= ASCII_NINE)) || 
                (('a' <= token[1]) && (token[1] <= 'f'))){
                    fputs("0e\n", outfile);
                    fprintf(outfile, "%s", token);
                }
            }
        }
        else{
            printf("Error: invalid token: juMP.\n");
            exit(1);
        }
        fputs("\n", outfile);
    }
    
    fclose(infile);
    fclose(outfile);
    return 0; 
}