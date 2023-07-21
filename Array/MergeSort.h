#ifndef CPP_MERGESORT_H
#define CPP_MERGESORT_H

void merge(int arr[], int start, int mid, int end) {
    int arrOneSize = mid - start + 1;
    int arrTwoSize = end - mid;

    int *arrOne = new int[arrOneSize];
    int *arrTwo = new int[arrTwoSize];

    for (int i = 0; i < arrOneSize; i++)
        arrOne[i] = arr[start + i];

    for (int i = 0; i < arrTwoSize; i++)
        arrTwo[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = start;
    while (i < arrOneSize && j < arrTwoSize) {
        if (arrOne[i] < arrTwo[j])
            arr[k++] = arrOne[i++];
        else
            arr[k++] = arrTwo[j++];
    }

    while (i < arrOneSize)
        arr[k++] = arrOne[i++];

    while (j < arrTwoSize)
        arr[k++] = arrTwo[j++];

    delete[] arrOne;
    delete[] arrTwo;
}

void mergeSort(int arr[], int start, int end) {
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

#endif //CPP_MERGESORT_H
