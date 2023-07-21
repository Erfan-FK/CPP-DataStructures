#include "iostream"
#include "Strings/Anagrams.h"
#include "Matrices/TriDiagonal.h"
using namespace std;

int main() {
    TriDiagonal triDiagonalMatrix(4);

    triDiagonalMatrix.set(0, 0, 1);
    triDiagonalMatrix.set(0, 1, 2);
    triDiagonalMatrix.set(1, 0, 3);
    triDiagonalMatrix.set(1, 1, 4);
    triDiagonalMatrix.set(1, 2, 5);
    triDiagonalMatrix.set(2, 1, 6);
    triDiagonalMatrix.set(2, 2, 7);
    triDiagonalMatrix.set(2, 3, 8);
    triDiagonalMatrix.set(3, 2, 9);
    triDiagonalMatrix.set(3, 3, 10);

    triDiagonalMatrix.display();
    return 0;
}