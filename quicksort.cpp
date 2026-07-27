#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &vec, int lb, int ub)
{
    int pivot = vec[lb];
    int start = lb + 1;
    int end = ub;

    while (true)
    {
        while (start <= ub && vec[start] <= pivot)
            start++;

        while (vec[end] > pivot)
            end--;

        if (start < end)
            swap(vec[start], vec[end]);
        else
            break;
    }

    swap(vec[lb], vec[end]);
    return end;
}

void quickSort(vector<int> &vec, int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(vec, lb, ub);
        quickSort(vec, lb, loc - 1);
        quickSort(vec, loc + 1, ub);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> vec(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    quickSort(vec, 0, n - 1);

    cout << "Sorted array: ";
    for (int x : vec)
    {
        cout << x << " ";
    }
}