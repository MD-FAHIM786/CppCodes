#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& vec, int lb, int mid, int ub) {
    int n1 = mid - lb + 1;
    int n2 = ub - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = vec[lb + i];
    for (int j = 0; j < n2; j++)
        R[j] = vec[mid + 1 + j];

    int i = 0, j = 0, k = lb;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& vec, int lb, int ub) {
    if (lb < ub) {
        int mid = lb + (ub - lb) / 2;

        mergeSort(vec, lb, mid);
        mergeSort(vec, mid + 1, ub);

        merge(vec, lb, mid, ub);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> vec(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    mergeSort(vec, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}