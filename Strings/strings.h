/**
 * @file strings.h
 * @author Maureen Wang, David Zhang
 * @brief This is the header file for the library file strings.c 
 * that declare all the functions
 * @version 0.1
 * @date 2022-04-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef STRINGS_H // Make sure we're not re-defining if included multiple times.
#define STRINGS_H

#include <stdio.h>
#include <stdlib.h>

/* DESCRIPTION: The strlen() function computes the length of the string s.
 * RETURN VALUE: The strlen() function returns the number of characters that
 * precede the terminating NUL character.
 */
int mystrlen(const char*);

/**
 * @brief The strcmp() function compares two strings
 * character by character till the end to determine
 * if they're identical
 * 
 * @return 0 if identical, negative value if the first string is smaller,
 * positive value if the first string is bigger.
 */
int mystrcmp(const char*, const char*);

/**
 * @brief The strcpy() function copy the source string to
 * destination string including the end of string character.
 * 
 * @return the destination string
 */
char* mystrcpy(char*, const char*);

/**
 * @brief The strcat() function concatenate the second string to 
 * the destination string. 
 * 
 * @return the destination string after concatenation
 */
char* mystrcat(char*, const char*);

/**
 * @brief The strchr() function find the substring of the string
 * starting at the character(with certain value)
 * 
 * @return the substring starting at the character, if the string
 * does not contain the character, the function returns null.
 */
char* mystrchr(const char*, int);


#endif
