#include "iostream"
#include "string"
#include "sstream"

#include "../Searchs/BinarySearch.h"

#ifndef CPP_ARRAY_H
#define CPP_ARRAY_H

template <class T>
class Array {
private:
    T *arr;
    int size;
    int length;

public:
    explicit Array(int size) {
        this->arr = new T[size];
        this->size = size;
        this->length = 0;
    }

    ~Array() {
        delete[] arr;
        this->arr = nullptr;
    }

//    O(1)
    bool add(T value) {
        if (length == size)
            return false;
        arr[length++] = value;
        return true;
    }

    int getSize() {
        return this->length;
    }

//    O(n)
    bool insert(int index, T value) {
        if (index >= length || length == size)
            return false;
        for (int i = length; i > index; i--)
            arr[i] = arr[i - 1];

        arr[index] = value;
        length++;
        return true;
    }

//    O(n)
    bool remove(int index) {
        if (index >= length)
            return false;
        for (int i = index; i < length - 1; i++)
            arr[i] = arr[i + 1];
        length--;
        return true;
    }

//    O(1)
    void set(int index, int value) {
        if (index  < 0 || index >= length)
            return;
        arr[index] = value;
    }

//    O(1)
    T get(int index) {
        if (index  < 0 || index >= length)
            throw std::out_of_range("Index out of range");
        return arr[index];
    }

//    get with []
    T operator[](int index) {
        if (index < 0 || index >= length)
            throw std::out_of_range("Index out of range");
        return arr[index];
    }

//    O(n)
    int linearSearch(T target) {
        for (int i = 0; i < length; i++)
            if (arr[i] == target)
                return i;
        return -1;
    }

//    O(logn)
    int binarySearch(T target) {
        return ::binarySearch(arr, target, 0, length - 1);
    }

//    O(n)
    T getMax() {
        int max = arr[0];
        for (int i = 1; i < length; i++)
            if (arr[i] > max)
                max = arr[i];

        return max;
    }

//    O(n)
    T getMin() {
        int min = arr[0];
        for (int i = 0; i < length; i++)
            if (arr[i] < min)
                min = arr[i];

        return min;
    }

//    O(n)
    T getSum() {
        int sum = 0;
        for (int i = 0; i < length; i++)
            sum += arr[i];

        return sum;
    }

//    O(n)
    T getAvg() {
        return getSum() / length;
    }

//    O(n)
    void reverse() {
        for (int i = 0, j = length - 1; i < j; i++, j--) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

//    O(n)
    void leftShift() {
        for (int i = 0; i < length - 1; i++)
            arr[i] = arr[i + 1];

        arr[length - 1] = 0;
    }

//    O(n)
    void rightSift() {
        for (int i = length - 1; i > 0; i--)
            arr[i] = arr[i - 1];

        arr[0] = 0;
    }

//    O(n)
//    Rotate the element by 1 right shift
    void rotate() {
        int lastElem = arr[length - 1];

        for (int i = length - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = lastElem;
    }

//    O(n^2),
//    Could have be done in O(n) using temp array
    void shift(int shift) {
        shift %= length;

        while (shift != 0) {
            rotate();
            shift--;
        }
    }

//    O(n)
//    Inserts an element in an ordered array
    int insertSorted(T value) {
        if (length == size)
            return -1;

        int i = length - 1;
        while (i >= 0 && arr[i] > value) {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1] = value;
        length++;
        return i;
    }

//    O(n)
//    Check if an array is sorted in Ascending way
    bool isSorted() {
        for (int i = 0; i < length - 1; i++)
            if (arr[i] > arr[i + 1])
                return false;
        return true;
    }

//    O(n)
//    Merges two Array and return a new one
//    Implementation of Union, Intersection and Difference of two array are similar to merge()
//    Time complexity for all three will be O(n) if the arrays are sorted otherwise they will be O(n^2)
    Array merge(Array &arr2) {
        Array arr3(this->getSize() + arr2.getSize());

        int i = 0, j = 0;

        while (i < this->length && j < arr2.length) {
            if (this->get(i) < arr2.get(j))
                arr3.add(this->get(i++));
            else
                arr3.add(arr2.get(j++));
        }

        while (i < this->getSize())
            arr3.add(this->get(i++));

        while (j < arr2.getSize())
            arr3.add(arr2.get(j++));

        return arr3;
    }

//    O(n)
    void display() {
        std::stringstream ss;
        ss << '[';

        for (int i = 0; i < length; i++) {
            if (i == length - 1)
                ss << arr[i];
            else
                ss << arr[i] << ',';
        }

        ss << ']';
        std::cout << ss.str() << std::endl;
    }
};

#endif //CPP_ARRAY_H
