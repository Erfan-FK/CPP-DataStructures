#ifndef CPP_BINARYSEARCH_H
#define CPP_BINARYSEARCH_H

template <class T>
int binarySearch(int arr[], T target, int start, int end) {
//  Recursive Approach

//        int mid = start + (end - start) / 2;
//        if (start <= end) {
//            if (arr[mid] == target)
//                return mid;
//            else if (target > arr[mid])
//                return binarySearch(target, mid + 1, end);
//            else
//                return binarySearch(target, start, mid - 1);
//        }


//  Iterative Approach
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
            return mid;
        else if (target > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
            return -1;
}
#endif //CPP_BINARYSEARCH_H
