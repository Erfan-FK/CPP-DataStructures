#ifndef CPP_TYPES_H
#define CPP_TYPES_H

char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    return c;
}

void toLowerCase(char s[]) {
    int size;
    for (size = 0; s[size] != '\0'; size++);

    for (int i = 0; i < size; i++)
        s[i] = toLowerCase(s[i]);
}

char toCapitalCase(char c) {
    if (c >= 'a' && c <= 'z')
        return c - ('a' - 'A');
    return c;
}

void toCapitalCase(char s[]) {
    int size;
    for (size = 0; s[size] != '\0'; size++);

    for (int i = 0; i < size; i++)
        s[i] = toCapitalCase(s[i]);
}

bool isAlphabetical(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool isAlphanumeric(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

bool isCapital(char c) {
    return (c >= 'A' && c <= 'Z');
}

bool isLower(char c) {
    return (c >= 'a' && c <= 'z');
}
#endif //CPP_TYPES_H
