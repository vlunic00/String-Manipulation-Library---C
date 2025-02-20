#ifndef STRING_UTILS_H 
#define STRING_UTILS_H

#include <stddef.h>

size_t string_length(const char *str);
size_t string_copy(char *dest, const char *src, size_t max_len);
int string_compare(const char *str1, const char *str2);
void string_to_upper(char *str);
void string_to_lower(char *str);
char *string_trim(const char *str);
void string_reverse(char *str);
char *remove_char(const char *str, const char removing_char);

#endif