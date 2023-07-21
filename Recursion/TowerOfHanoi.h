#ifndef CPP_TOWEROFHANOI_H
#define CPP_TOWEROFHANOI_H

#include "iostream"

void toh(int n, int a, int b, int c) {
    if (n > 0) {
        toh(n - 1, a, c, b);
        printf("%d to %d\n", a, c);
        toh(n - 1, b, a, c);
    }
}
#endif //CPP_TOWEROFHANOI_H
