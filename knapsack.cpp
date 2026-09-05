#include <bits/stdc++.h>
using namespace std;

void knapsack(int n, int w, const vector<int> &wt, const vector<int> &pt)
{
    vector<vector<int>> cost(n + 1, vector<int>(w  + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
            {
                cost[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                cost[i][j] = max(cost[i - 1][j], cost[i - 1][j - wt[i - 1]] + pt[i - 1]);
            }
            else
            {
                cost[i][j] = cost[i - 1][j];
            }       
        }
    }

    cout << "Maximum value in Knapsack = " << cost[n][w] << endl;

    vector<int> selectedItems;
    int remainingWeight = w;
    for (int i = n; i > 0 && remainingWeight > 0; i--)
    {
        if (cost[i][remainingWeight] != cost[i - 1][remainingWeight])
        {
            selectedItems.push_back(i - 1);
            remainingWeight -= wt[i - 1];
        }
    }

    reverse(selectedItems.begin(), selectedItems.end());
    cout << "Selected items:\n";
    if (selectedItems.empty())
    {
        cout << "None\n";
    }
    else
    {
        for (int index : selectedItems)
        {
            cout << "Item " << index + 1 << " (weight: " << wt[index]
                 << ", profit: " << pt[index] << ")\n";
        }
    }
}

int main()
{
    int n, w;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> wt(n), pt(n);
    cout << "Enter the weights of the items:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    cout << "Enter the profits of the items:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> pt[i];
    }

    cout << "Enter the maximum weight of the knapsack: ";
    cin >> w;

    knapsack(n, w, wt, pt);

    return 0;
}