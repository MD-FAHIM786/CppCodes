#include<stdio.h>

void LeftRotate(int arr[], int l) {
    int temp = arr[0];   // store first element

    for(int i = 0; i < l-1; i++) {
        arr[i] = arr[i+1];
    }

    arr[l-1] = temp;     // put first element at last

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