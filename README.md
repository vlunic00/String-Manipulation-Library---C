# String Manipulation Library in C<br><br>
This library is an extension to the current string.h library, that accounts for the possibility of the argument strings being NULL.<br>
Every function has a check before the actual functionality is executed.<br><br>
The library currently has the following functions:<br>
- `size_t string_length(const char *str)` - Checks if the str string is NULL and if not returns it's length. If it is NULL returns 0
- `size_t string_copy(char *dest, const char *src, size_t max_len)` - Prevents buffer overflows by choosing between the size of the source or the passed max_length
- `int string_compare(const char *str1, const char *str2)` - Has a check if either str1, str2 or both are NULL
- `void string_to_upper(char *str)` - Checks if str is NULL before calling the toupper() function
- `void string_to_lower(char *str)` - Checks if str is NULL before calling the tolower() function
