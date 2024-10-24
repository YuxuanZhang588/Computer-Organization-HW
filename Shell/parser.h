/* Interface for the string tokenization library. */


/* Returns an array of strings containing tokens extracted from the supplied
 * string.
 */
char** parseCommand(const char* cmdLine, int* bg);
