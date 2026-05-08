#include <stdio.h>

int BinarySearch(int A[], int n, int item) {
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (A[mid] == item) {
            return mid;
        } else if (A[mid] < item) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    int A[] = {1, 3, 5, 6, 7, 9};  // sorted ascending for binary search
    int idx = BinarySearch(A, 6, 6);
    if (idx >= 0) {
        printf("Item found at index: %d\n", idx);
    } else {
        printf("Item not found\n");
    }
    return 0;
}

