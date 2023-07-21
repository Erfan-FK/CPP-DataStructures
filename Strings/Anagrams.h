#ifndef CPP_ANAGRAMS_H
#define CPP_ANAGRAMS_H

#include "Types.h"

const int ALPHABETS = 26;

bool isAnagram(char str1[], char str2[]) {
    int size1, size2;
    for (size1 = 0; str1[size1] != '\0'; size1++);
    for (size2 = 0; str2[size2] != '\0'; size2++);

    if (size1 != size2)
        return false;

    int counts[ALPHABETS] = {0};
    for (int i = 0; i < size1; i++) {
        char c = toLowerCase(str1[i]);
        if (isAlphabetical(c))
            counts[c - 'a']++;
    }

    for (int j = 0; j < size2; j++) {
        char c = toLowerCase(str2[j]);
        if (isAlphabetical(c))
            counts[c - 'a']--;
        if (counts[c - 'a'] < 0)
            return false;
    }

    return true;
}
#endif //CPP_ANAGRAMS_H
