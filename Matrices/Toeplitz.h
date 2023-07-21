#ifndef CPP_TOEPLITZ_H
#define CPP_TOEPLITZ_H

#include "iostream"
using namespace std;

class Toeplitz {
private:
    int size;
    int* A;

public:
    Toeplitz() {
        this->size = 5;
        this->A = new int[2 * size - 1];
    }

    explicit Toeplitz(int size) {
        this->size = size;
        this->A = new int[2 * size - 1];
    }

    void set(int i, int j, int value) {
        A[i - j + size - 1] = value;
    }

    int get(int i, int j) {
        return A[i - j + size - 1];
    }

    void display() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }

    ~Toeplitz() {
        delete[] A;
    }
};

#endif //CPP_TOEPLITZ_H
