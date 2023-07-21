#ifndef CPP_LOWERTRIANGLE_H
#define CPP_LOWERTRIANGLE_H

#include "iostream"
using namespace std;

class LowerTriangle {
private:
    int size;
    int *A;

public:
    LowerTriangle() {
        this->size = 5;
        this->A = new int[15];
    }

    explicit LowerTriangle(int size) {
        this->size = size;
        this->A = new int [(size * (size + 1)) / 2];
    }

//    Row-Majored Formula (i * (i + 1)) / 2 + j
//    Column-Majored Formula + (i - j)
    void set(int i, int j, int value) {
        if (i >= j)
            this->A[(i * (i + 1)) / 2 + j] = value;

    }

    int get(int i, int j) {
        if (i < j)
            return 0;
        return A[(i * (i + 1) / 2) + j];
    }

    void display() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; ++j) {
                cout << get(i, j);
            }
            cout << endl;
        }
    }

    ~LowerTriangle() {
        delete[] this->A;
    }
};

#endif //CPP_LOWERTRIANGLE_H
