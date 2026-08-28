#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int g(const vector<vector<int>> &cost,
      int currentCity,
      vector<bool> &remaining)
{
    int n = cost.size();

    // If s is empty, return to the starting city.
    bool noCityLeft = true;
    for (int city = 1; city < n; city++)
    {
        if (remaining[city])
        {
            noCityLeft = false;
            break;
        }
    }

    if (noCityLeft)
        return cost[currentCity][0];

    int bestCost = INT_MAX;

    // g(i, s) = min { C(i, j) + g(j, s - j) }
    for (int nextCity = 1; nextCity < n; nextCity++)
    {
        // If j belongs to s, try j as the next city.
        if (remaining[nextCity])
        {
            // Remove j from s to create s - j.
            remaining[nextCity] = false;

            int tourCost = cost[currentCity][nextCity] +
                           g(cost, nextCity, remaining);

            bestCost = min(bestCost, tourCost);

            // Restore s before trying another choice.
            remaining[nextCity] = true;
        }
    }

    return bestCost;
}

int main()
{
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));

    cout << "Enter the cost matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];
    }

    vector<bool> remaining(n, false);
    for (int city = 1; city < n; city++)
        remaining[city] = true;

    int answer = g(cost, 0, remaining);

    cout << "Minimum cost = " << answer << endl;

    return 0;
}