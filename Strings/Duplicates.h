#ifndef CPP_DUPLICATES_H
#define CPP_DUPLICATES_H

#include "iostream"
#include "Types.h"

const int ALPHABETS = 26;

void findDuplicates(char string[]) {
    int duplicates[ALPHABETS * 2] = {0};

    int size;
    for (size = 0; string[size] != '\0'; size++);

    for (int i = 0; i < size; i++) {
        char c = string[i];
        if (isAlphabetical(c)) {
            if (isLower(c))
                duplicates[c - 'a']++;
            else
                duplicates[c - 'A' + ALPHABETS]++;
        }
    }

    for (int i = 0; i < ALPHABETS * 2; i++) {
        if (duplicates[i] > 0) {
            if (i < ALPHABETS)
                std::cout << (char)(i + 'a') << " -> " << duplicates[i] << std::endl;
            else
                std::cout << (char)(i + 'A' - ALPHABETS) << " -> " << duplicates[i] << std::endl;
        }
    }
}

#endif //CPP_DUPLICATES_H
