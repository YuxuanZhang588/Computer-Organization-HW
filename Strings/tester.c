/**
 * @file tester.c
 * @author Maureen Wang, David Zhang
 * @brief This is the tester file for the string functions that we created
 * @version 0.1
 * @date 2022-04-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strings.h"

#define SIZE 100

int main(){
  char* lib_str = (char*) malloc(SIZE * sizeof(char));
  char* my_str = (char*) malloc(SIZE * sizeof(char));
  strcpy(lib_str, "I'm ready for summer break!");
  mystrcpy(my_str, "I'm ready for summer break!");

  printf("%s\n", lib_str);
  printf("%s\n", my_str);

  int lib_len = strlen(lib_str);
  int my_len = mystrlen(my_str);

  printf("lib len: %d\nmy len: %d\n", lib_len, my_len);

  if(mystrcmp(lib_str, my_str)){
    printf("strings DO NOT match!\n");
  }else{
    printf("strings match!\n");
  }
  
  //Test mystrcpy and mystrcat
  char* second_str = (char*) malloc(SIZE * sizeof(char));
  mystrcpy(second_str, " Not really...");
  mystrcat(my_str,second_str);
  printf("%s\n", my_str);
  char* test_str = (char*) malloc(SIZE * sizeof(char));
  mystrcpy(test_str, "This hobbit was a very well-to-do hobbit, and his name was Baggins.");
  printf("%s\n", test_str);

  // Test mystrchr
  printf("%s\n", second_str);
  char* substr1=mystrchr(second_str, 'r'); // should print really...
  printf("%s\n", substr1);
  char* substr2=mystrchr(second_str, 'l'); // should print ot lly...
  printf("%s\n", substr2);
  char* substr3=mystrchr(second_str, '.'); // should print ...
  printf("%s\n", substr3);
  char* substr4=mystrchr(second_str, 'm'); // should be a NULL
  if (substr4 == NULL){
    printf("You have a NULL pointer!");
  }
  else {
    printf("%s\n", substr4);
  }

  free(lib_str);
  free(my_str);
  free(second_str);
  free(test_str);
}
