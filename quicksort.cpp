#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &vec, int LI, int UI)
{
    int pivot = vec[LI];
    int i = LI + 1, j = UI;
    while (true)
    {
        while (i <= UI && vec[i] <= pivot)
            i++;

        while (vec[j] > pivot)
            j--;
        if (i < j)
            swap(vec[i], vec[j]);
        else
            break;
    }

    swap(vec[LI], vec[j]);
    return j;
}

int quickSort(vector<int> &vec, int LI, int UI)
{
    if (LI < UI)
    {
        int loc = partition(vec, LI, UI);
        quickSort(vec, LI, loc - 1);
        quickSort(vec, loc + 1, UI);
    }
    return 0;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> vec(n);

    cout << "Enter The elements: ";
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    quickSort(vec, 0, n - 1);

    cout << "Sorted elements: ";
    for (int x : vec)
        cout << x << " ";
    cout << "\n";
}