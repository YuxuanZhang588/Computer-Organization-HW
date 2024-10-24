/* Functions for validating whether a given integer can be converted
 * to fixed-width binary.
 */


/* validate_unisigned() checks whether an integer can be converted to unsigned.
 *
 * ARGUMENTS:
 *     int_to_convert: An integer.
 *     num_bits: The number of bits in the unsigned representation.
 * RETURNS:
 *     1 (true) if int_to_convert can be represented using a num_bits-bit
 *     unsigned integer; 0 (false) otherwise.
 */
short validate_unisigned(long int_to_convert, long num_bits);


/* validate_twos() checks whether an integer can be converted to twos complement.
 *
 * ARGUMENTS:
 *     int_to_convert: An integer.
 *     num_bits: The number of bits in the twos complement representation.
 * RETURNS:
 *     1 (true) if int_to_convert can be represented using a num_bits-bit
 *     signed integer; 0 (false) otherwise.
 */
short validate_twos(long int_to_convert, long num_bits);