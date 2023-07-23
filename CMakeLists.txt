cmake_minimum_required(VERSION 3.25)
project(CPP)

set(CMAKE_CXX_STANDARD 23)

add_executable(CPP Main.cpp Recursion/SumOfN.h Recursion/Factorial.h Recursion/Power.h Recursion/Fibonacci.h Recursion/TowerOfHanoi.h Array/Array.h Array/BinarySearch.h Array/MergeSort.h Strings/Reverse.h Strings/Palindrome.h Strings/Types.h Strings/Duplicates.h Strings/Anagrams.h Matrices/Diagonal.h Matrices/LowerTriangle.h Matrices/Symmetric.h Matrices/TriDiagonal.h Matrices/Toeplitz.h Matrices/Sparse.h Polynomial/Polynomial.h)
