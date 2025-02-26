#include <stdio.h>
#include "string_utils.h"


int main(){
    char str[10] = "  hi there";
    char str2[20] = "he llo   there";
    char str3[4] = " h ";
    char str4[100] = "Testing for words in this sentance";
    int words = num_of_words(str);
    int words2 = num_of_words(str2);
    int words3 = num_of_words(str4);

    printf("%d, %d, %d", words, words2, words3);

}