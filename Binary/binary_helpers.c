/****************************************************************/
// THE FOLLOWING FUNCTIONS ARE PROVIDED FOR YOU. DO NOT MODIFY!
/****************************************************************/

#include <stdio.h>

short validate_binary(short* binary_array, long num_bits){
    for(long i=0; i<num_bits; i++){
        if(binary_array[i] != 0 && binary_array[i] != 1){
            return 0;
        }
    }
    return 1;
}


void print_binary(short* binary_array, long num_bits){
    for(long i=0; i<num_bits; i++){
        if(binary_array[i] == 0 || binary_array[i] == 1){
            printf("%d", binary_array[i]);
        } else {
            printf("_");
        }
    }
}


void read_binary(char* binary_string, short* binary_array, long num_bits){
    for(long i=0; i < num_bits; i++){
        binary_array[i] = binary_string[i] - '0';
    }
}
