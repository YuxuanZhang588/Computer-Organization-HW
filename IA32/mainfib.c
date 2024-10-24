/*
 * Main function that calls the IA32 fib function.
 * Takes one integer as a command line argument.
 *
 */
#include<stdio.h>
#include<stdlib.h>

// you will implement this function in IA32 in the files fib.s.
// The Makefile will take care of linking it into the executable.
int fib(int n);

int main(int argc, char *argv[]) {

  int n, res;

  if(argc != 2) {
    printf("usage: ./mainfib n\n");
    exit(1);
  }
  n = atoi(argv[1]);
  if(n < 1){
    printf("n must be positive\n");
    exit(1);
  }

  res = fib(n);
  printf("The %dth Fibonacci number is %d\n", n, res);
}
