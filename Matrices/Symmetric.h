#ifndef CPP_SYMMETRIC_H
#define CPP_SYMMETRIC_H

#include "iostream"
using namespace std;

class Symmetric {
private:
    int size;
    int *A;

public:
    Symmetric() {
        this->size = 5;
        this->A = new int[15];
    }

    explicit Symmetric(int size) {
        this->size = size;
        this->A = new int [(size * (size + 1)) / 2];
    }

//    Row-Majored Formula (i * (i + 1)) / 2 + j
//    Column-Majored Formula + (i - j)
    void set(int i, int j, int value) {
        if (i >= j)
            this->A[(i * (i + 1)) / 2 + j] = value;
        else
            this->A[(j * (j + 1)) / 2 + i] = value;

    }

    int get(int i, int j) {
        if (i >= j)
            return this->A[(i * (i + 1)) / 2 + j];
        else
            return this->A[(j * (j + 1)) / 2 + i];
    }

    void display() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; ++j) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }

    ~Symmetric() {
        delete[] this->A;
    }
};

#endif //CPP_SYMMETRIC_H
