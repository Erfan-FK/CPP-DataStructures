#ifndef CPP_DIAGONAL_H
#define CPP_DIAGONAL_H

#include "iostream"

class Diagonal {
private:
    int size;
    int* A;

public:
    Diagonal() {
        this->size = 10;
        this->A = new int[size];
    }

    explicit Diagonal(int size) {
        this->size = size;
        this->A = new int[size];
    }

    void set(int row, int column, int value) {
        if (row == column)
            this->A[row] = value;
    }

    int get(int row, int column) {
        if (row == column)
            return this->A[row];
        return 0;
    }

    void display() {
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                if (i == j)
                    std::cout << this->A[i] << " ";
                else
                    std::cout << "0 ";
            }
            std::cout << std::endl;
        }
    }

    ~Diagonal() {
        delete[] this->A;
    }
};

#endif //CPP_DIAGONAL_H
