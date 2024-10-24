/* HW2 Binary
 * 
 * Time Spent: 5 hours
 * 
 * Author: Yuxuan Zhang
 * 
 */
short validate_unisigned(long int_to_convert, long num_bits){
    long max_number = (1L << num_bits) - 1; 
    if((int_to_convert >= 0) && (num_bits > 0) && 
    (max_number >= int_to_convert)){
        return 1;
    }

    return 0;
}


short validate_twos(long int_to_convert, long num_bits){
    long twos_max_number = (1L << (num_bits-1)) - 1;
    long twos_min_number = - (1L << (num_bits-1));

    if(num_bits > 0){
        if((int_to_convert >= twos_min_number) && 
        (int_to_convert <= twos_max_number)){
            return 1;
        }
    }

    return 0;
}