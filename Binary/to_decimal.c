#include <stdio.h>
#include <stdlib.h>

//Helper functions implemented for you.
#include "binary_helpers.h"

//Helper functions you need to implement.
#include "validate_binary.h"

//Functions you need to implement below.
long unsigned_to_int(short* unsigned_input, long num_bits);
long twos_to_int(short* twos_input, long num_bits);

//You should not modify main.
int main(int argc, char* argv[]){
    short binary_input[MAX_BITS];
    long from_unsigned, from_twos, num_bits;

    //Read and validate input.
    if(argc != 3){
        printf("usage: ./to_decimal num_bits binary_string\n");
        return 1;
    }
    num_bits = atoi(argv[1]);
    if(num_bits > MAX_BITS || num_bits < 0){
        printf("num_bits must be between 0 and %d\n", MAX_BITS);
        return 1;
    }
    read_binary(argv[2], binary_input, num_bits);
    if( !validate_binary(binary_input, num_bits) ){
        printf("not valid %ld-bit binary\n", num_bits);
        return 1;
    }

    //Convert binary_input (as unsigned) to int.
    from_unsigned = unsigned_to_int(binary_input, num_bits);
    printf("converted from unsigned to int: %ld\n", from_unsigned);

    //Convert binary_input (as twos complement) to int.
    from_twos = twos_to_int(binary_input, num_bits);
    printf("converted from twos complement to int: %ld\n", from_twos);

    return 0;
}


/* unsigned_to_int() converts an unsigned binary value into an integer.
 *
 * ARGUMENTS:
 *   unsigned_input: an array of size equal to the constant num_bits
 *           representing an integer in unsigned binary. Because the number
 *           reads from left to right, the most significant bit is at index
 *           0 in the array, and the 1s digit is at index num_bits - 1.
 *   num_bits: The size of the array.
 * RETURNS:
 *   int_output: an integer representing the same numerical value as
 *           unsigned_input.
 */
long unsigned_to_int(short* unsigned_input, long num_bits){
    long int_output = 0;
    for(long i = 0; i <num_bits; i++){
        if(unsigned_input[i] == 1){
            long add_value= (long)1 << (num_bits-1-i);
            int_output += add_value; 
        }
    }
    return int_output;
}

/* twos_to_int() converts a twos complement binary value into an integer.
 *
 * ARGUMENTS:
 *   twos_input: an array of size equal to the constant num_bits representing
 *           an integer in twos complement binary. Because the number reads
 *           from left to right, the sign bit is at index 0, and the 1s
 *           digit is at index num_bits - 1.
 *   num_bits: The size of the array.
 * RETURNS:
 *   int_output: an integer representing the same numerical value as
 *           twos_input.
 */
long twos_to_int(short* twos_input, long num_bits){
    long int_output = 0;
    if(twos_input[0] == 1){
        int_output -= ((long)1 << (num_bits-1));
    }
    for(long i = (num_bits-2); i >= 0; i--){
        if(twos_input[num_bits-1-i] == 1){
            int_output += ((long)1 << i);
        }
    }

    return int_output;
}
