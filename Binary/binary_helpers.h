/* Helper functions for HW2: Binary.
 * Author: Bryce
 */

#ifndef MAX_BITS
  #define MAX_BITS 63
#endif


/* Checks that all entries of an array are 1 or 0.
 *
 * ARGUMENTS:
 *     binary_array: An array with num_bits valid entries.
 *     num_bits: The size of the array.
 * RETURNS:
 *     1 (true) if all entries are 1 or 0, 0 (false) otherwise.
 */
short validate_binary(short* binary_array, long num_bits);


/* Prints the 1s and 0s in an array.
 *
 * All entries that are not 1 or 0 are printed as the '_' character.
 *
 * ARGUMENTS:
 *     binary_array: An array with num_bits valid entries.
 *     num_bits: The size of the array.
 */
void print_binary(short* binary_array, long num_bits);


/* read_binary() collects a binary value entered by the user.
 *
 * ARGUMENTS:
 *     binary_array: An array with num_bits valid entries. Its entries
 *         will be overwritten with the input entered by the user.
 *     num_bits: The number of bits to read into the binary array.
 */
void read_binary(char* binary_string, short* binary_array, long num_bits);
