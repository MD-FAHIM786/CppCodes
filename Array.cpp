#include<stdio.h>
int main() {
    int i,j, A[8]={10,20,30}, B[5]={40,50,60,70,80};
    j=0;

    for(i=3;i<8;i++) {
        A[i]=B[j];
        j++;
    }

    for(i=0;i<8;i++) {
        printf("%d ", A[i]);
    }

}