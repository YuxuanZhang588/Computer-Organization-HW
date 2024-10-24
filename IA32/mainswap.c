/*
 * Main function that calls the IA32 swap function.
 * Takes two integers as command line arguments.
 */
#include<stdio.h>
#include<stdlib.h>

// You will implement this function in IA32 in the file swap.s.
// The Makefile will take care of linking it into the executable.
void swap(int *x, int *y); // x and y are passed as pointers

int main(int argc, char *argv[]) {

  int a, b;

  if(argc != 3) {
    printf("usage: ./mainswap a b\n");
    exit(1);
  }
  a = atoi(argv[1]);
  b = atoi(argv[2]);

  printf("before swap a = %d, b = %d\n",a,b);
  swap(&a, &b);
  printf("after swap a = %d, b = %d\n",a,b);
}
