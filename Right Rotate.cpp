#include<stdio.h>

void LeftRotate(int arr[], int l) {
    int temp = arr[l-1];   // store last element in temp variable

    for(int i = l-1; i >= 0; i--) {
        arr[i] = arr[i-1];
    }

    arr[0] = temp;     // put last element at fast position

    for(int i = 0; i < l; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    LeftRotate(arr, 5);
    return 0;
}