#include<bits/stdc++.h>
#include<vector>
using namespace std;

bool isSorted(vector<int> arr, int n) {
    if (n == 0 || n == 1) {
        return true; // An empty array or single element array is considered sorted
    }

    return (arr[n-1] >= arr[n-2]) && isSorted(arr, n - 1);
}

int main() {
    vector<int> arr = {};

    cout << isSorted(arr, arr.size()) << endl; // Output: 1 (true)

    return 0;
}