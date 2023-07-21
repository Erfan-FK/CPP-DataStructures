#ifndef CPP_REVERSE_H
#define CPP_REVERSE_H

void reverse(char string[]) {
    int i, j;
    for (j = 0; string[j] != '\0'; j++);
    j--;
    for (i = 0; i < j; i++, j--) {
        char tmp = string[i];
        string[i] = string[j];
        string[j] = tmp;
    }
}


#endif //CPP_REVERSE_H
