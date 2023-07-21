#ifndef CPP_FIBONACCI_H
#define CPP_FIBONACCI_H

//Recursive function to calculate fibonacci using memoization & dynamic programming
int fib(int n) {
    static int memo[101];

    if (n <= 1) {
        memo[n] = n;
        return n;
    } else {
        if (memo[n] != 0)
            return memo[n];
        else {
            memo[n] = fib(n - 1) + fib(n - 2);
            return memo[n];
        }
    }
}

#endif //CPP_FIBONACCI_H
