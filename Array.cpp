#include <bits/stdc++.h>
using namespace std;

void create(int arr[], int n);
void traverse(int arr[], int n);
void update(int arr[], int n);
void insert(int arr[], int &n);
void del(int arr[], int &n);

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    create(arr, n);
    traverse(arr, n);

    update(arr, n);
    traverse(arr, n);

    insert(arr, n);
    traverse(arr, n);

    del(arr, n);
    traverse(arr, n);

    return 0;
}

void create(int arr[], int n)
{
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void traverse(int arr[], int n)
{
    cout << "Index  : ";
    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
    }
    cout << "\nElement: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void update(int arr[], int n)
{
    int index, element;
    cout << "Enter index which will be updated: ";
    cin >> index;

    if (index < 0 || index >= n)
    {
        cout << "Invalid Index\n";
        return;
    }

    cout << "Enter element: ";
    cin >> element;

    arr[index] = element;
}

void insert(int arr[], int &n)
{
    int index, element;
    cout << "Enter index where element will be inserted: ";
    cin >> index;

    if (index < 0 || index > n)
    {
        cout << "Invalid Index\n";
        return;
    }

    cout << "Enter element: ";
    cin >> element;

    for (int i = n; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[index] = element;
    n++;
}

void del(int arr[], int &n)
{
    int index;
    cout << "Enter index which will be deleted: ";
    cin >> index;

    if (index < 0 || index >= n)
    {
        cout << "Invalid Index\n";
        return;
    }

    for (int i = index; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;
}
