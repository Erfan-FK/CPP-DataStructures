#ifndef CPP_POWER_H
#define CPP_POWER_H

int pow(int m, int n) {
    if (n == 0)
        return 1;
    if (n < 0)
        return pow(1 / m, -n);
    if (n % 2 == 0)
        return pow(m * m, n / 2);
    else
        return m * pow(m * m, n / 2);
}

#endif //CPP_POWER_H
