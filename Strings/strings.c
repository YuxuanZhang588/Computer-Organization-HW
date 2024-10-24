/**
 * @file strings.c
 * @author Maureen Wang, David Zhang
 * @brief This file is the library containing some of the string functions in C 
 * that we write on our own
 * 
 * Time Spent: 2 hours writing + 0.5 hour of debugging
 * 
 * @version 0.1
 * @date 2022-04-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "strings.h"


int mystrlen(const char* s){
  int count = 0;
  // Keep going until we reach the end of string character
  while(*s !='\0'){
    // Update the count
    count++;
    // increment the pointer to points to the next element
    s++;
  }
  return count;
}


int mystrcmp(const char* s1, const char* s2){
  // Keep increamenting both pointer until 
  // a difference occurs
  while ( (*s1 !='\0') && (*s2 !='\0') && (*s1 == *s2)){
    s1++;
    s2++;
  }
  // Exit the loop means either we reach the end 
  // or a difference has occurred. 
  // If the character is still the same (\0), that means
  // We successfully reach the end, so just return 0
  if (*s1 == *s2){
    return 0;
  }
  else{
    return *s1 - *s2;
  }
}

char* mystrcpy(char* str_des, const char* str_src){
  // need to store the pointer
  char* beginning=str_des;
  while (*str_src != '\0'){
    // Let the destination points to the location that 
    // the source point to as well.
    *str_des = *str_src;
    // increment both pointer
    str_src++;
    str_des++;
  }
  // the destination needs to have the terminating character!
  *str_des = '\0';
  // return the stored pointer that points to the beginning
  return beginning;
}

char* mystrcat(char* s1, const char* s2){
  // If one of the two string is null, 
  // concatenation failed
  if (s1==NULL || s2==NULL){
    printf("EMPTY STRING!!!INVALID!!!");
  }
  // Need to store the pointer
  char* new_str=s1;
  int length=mystrlen(s1);
  // Let the pointer point to the end of s1
  s1+=length;
  // copy s2 and attach to the end of s1.
  mystrcpy(s1, s2);
  // return the pointer that points to the beginning
  return new_str;
}

char* mystrchr(const char* s, int character){
  // First check if the string is null.
  if (s==NULL){
    printf("There is no character in a null string!");
    return NULL;
  }
  // Need a string of type char* 
  char* locator = (char*) s;
  // Read until the end of string
  while (*locator != '\0'){
    // If the element it points to is the character, 
    // we find it and should return the substring from
    // that element, which is just the locator.
    // Also, we need to transform number to character
    if (*locator == (char) character){ 
      return locator;
    }
    locator++;
  }
  // If character is the terminating \0, return the pointer
  // that points to the end of string
  if (*locator == character){
    return locator;
  }
  // If we each this line, that means the character we want
  // is not in s, so return null;
  return NULL;
}
