#include<stdio.h>

void DeletingFromArray(int arr[], int n, int size, int pos) {
    for(int i=pos; i< n-1; i++) {
        arr[i] = arr[i+1];
    }
    n--;

    for(int i=0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[5] = {1,2,3,4,5};
    DeletingFromArray(arr,5,5,2);
}