#ifndef CPP_PALINDROME_H
#define CPP_PALINDROME_H

#include "Types.h"

bool isPalindrome(char string[]) {
    int i, j;
    for (j = 0; string[j] != '\0'; j++);
    i = 0, j--;

    while (i < j) {
        while (i < j && !isAlphabetical(string[i]))
            i++;
        while (i < j && !isAlphabetical(string[j]))
            j--;

        char left = toLowerCase(string[i]);
        char right = toLowerCase(string[j]);

        if (left != right)
            return false;
        i++, j--;
    }
    return true;
}
#endif //CPP_PALINDROME_H
