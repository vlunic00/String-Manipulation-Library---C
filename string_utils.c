#include "string_utils.h"
#include <string.h>
#include <ctype.h>


size_t string_length(const char *str){
    if (str == NULL){
        return 0;
    }

    size_t length = 0;
    
    while(str[length] != '\0'){
        length++;
    }
    return length;
}

size_t string_copy(char *dest, const char *src, size_t max_len) {
    if (!dest || !src || max_len == 0) return 0;

    size_t src_len = string_length(src);
    size_t copy_len = (src_len < max_len - 1) ? src_len : max_len - 1;

    memcpy(dest, src, copy_len);
    dest[copy_len] = '\0';

    return copy_len;
}

int string_compare(const char *str1, const char *str2) {
    if (str1 == NULL && str2 == NULL) return 0;
    if (str1 == NULL) return -1; 
    if (str2 == NULL) return 1;  
    return strcmp(str1, str2);
}

void string_to_upper(char *str) {
    if (str == NULL) return;
    for (size_t i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void string_to_lower(char *str) {
    if (str == NULL) return;
    for (size_t i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}
