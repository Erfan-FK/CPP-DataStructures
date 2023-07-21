#ifndef CPP_TRIDIAGONAL_H
#define CPP_TRIDIAGONAL_H

#include "iostream"
using namespace std;

class TriDiagonal {
private:
    int size;
    int *A;

public:
    TriDiagonal() {
        this->size = 5;
        this->A = new int[13];
    }

    explicit TriDiagonal(int size) {
        this->size = size;
        this->A = new int [3 * size - 2];
    }

    void set(int i, int j, int value) {
        if (i == j) {
            A[i] = value; // Main Diagonal
        } else if (i == j + 1) {
            A[size + j] = value; // Upper Diagonal
        } else if (i == j - 1) {
            A[2 * size + i - 1] = value; // Lower Diagonal
        }
    }

    int get(int i, int j) {
        if (i == j) {
            return A[i]; // Main Diagonal
        } else if (i == j + 1) {
            return A[size + j]; // Upper Diagonal
        } else if (i == j - 1) {
            return A[2 * size + i - 1]; // Lower Diagonal
        }
        return 0;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }

    ~TriDiagonal() {
        delete[] this->A;
    }
};

#endif //CPP_TRIDIAGONAL_H
