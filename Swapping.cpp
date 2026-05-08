#include<stdio.h>

void swapping(int arr[],int arr1[], int l) {

    int mid = l/2;
    for (int i = mid+1; i < l ; i++) {
        arr1[i-(mid+1)] = arr[i];
    }

        arr1[mid] = arr[mid];

    for (int i = 0; i < mid; i++) {
          arr1[i+(mid+1)] = arr[i];
    }

    for(int i = 0; i < l; i++) {
        printf("%d ", arr1[i]);
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int arr1[9];
    swapping(arr,arr1,9);

    return 0;
}