#ifndef CPP_FACTORIAL_H
#define CPP_FACTORIAL_H

//Recursive function to calculate the factorial of a number n
int factorialRecurs(int n){
    if (n < 0)
        return 0;
    if (n == 0 || n == 1)
        return 1;
    return factorialRecurs(n - 1) * n;
}

//Iterative function to calculate the factorial of a number n
int factorialIter(int n) {
    int sum = n;

    while (n > 0) {
        sum *= n--;
    }

    return sum;
}
#endif //CPP_FACTORIAL_H
