#include <stdio.h>

int main() {
    int A[6] = {1, 2, 3, 4, 5, 6};
    int temp, i;

    temp = A[5];          // store last element

    for(i = 5; i > 0; i--) {
        A[i] = A[i - 1];  // shift right
    }

    A[0] = temp;          // put last element at first

    for(i = 0; i < 6; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
