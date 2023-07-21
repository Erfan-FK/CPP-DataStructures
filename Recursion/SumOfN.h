#ifndef CPP_SUMOFN_H
#define CPP_SUMOFN_H

//Recursive method to find sum of first n natural numbers
int sumOfNRecurs(int n) {
    if (n == 0)
        return 0;

    return sumOfNRecurs(n - 1) + n;
}

//Iterative method to find sum of first n natural numbers
int sumOfNIter(int n) {
    int sum = 0;

    while (n > 0)
        sum += n--;

    return sum;
}

#endif //CPP_SUMOFN_H
