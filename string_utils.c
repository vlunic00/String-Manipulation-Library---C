#include "string_utils.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>


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

char *string_trim(const char *str) {
    if (str == NULL) return NULL;

    size_t start = 0;
    while (isspace((unsigned char)str[start])) {
        start++;
    }

    size_t end = string_length(str);
    while (end > start && isspace((unsigned char)str[end - 1])) {
        end--;
    }

    size_t trimmed_len = end - start;
    char *trimmed_str = (char *)malloc(trimmed_len + 1);
    if (trimmed_str == NULL) return NULL;

    memcpy(trimmed_str, str + start, trimmed_len);
    trimmed_str[trimmed_len] = '\0';

    return trimmed_str;
}

void string_reverse(char *str) {
    if (str == NULL) return;

    size_t len = string_length(str);
    for (size_t i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

char *remove_char(const char *str, const char removing_char){
    if (str == NULL) return NULL;
    size_t original_length = string_length(str);
    size_t altered_length = original_length;

    for(int i = 0; i < original_length; i++){
        if(str[i] == removing_char){
            altered_length--;
        }
    }

    char *altered_str = (char *)malloc(altered_length + 1);
    int current_index = 0;
    
    for (int i = 0; i < original_length; i++){
        if(str[i] != removing_char){
            altered_str[current_index] = str[i];
            current_index++;
        }
    }

    altered_str[altered_length] = '\0';

    return altered_str;
}

int num_of_words(const char *str){
    if (str == NULL) return 0;
    size_t str_len = string_length(str);
    int word_counter = 0;
    bool can_be_new_word = true;
        for(int i = 0; i < str_len; i++){
            if(str[i] != ' ' && can_be_new_word){
                word_counter++;
                can_be_new_word = false;
            }
            else if(str[i] == ' ' && !can_be_new_word){
                can_be_new_word = true;
            }
        }
    return word_counter;
}
