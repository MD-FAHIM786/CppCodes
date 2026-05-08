#include <bits/stdc++.h>
#include <vector>
using namespace std;

void printSubsets(vector<int> &nums, vector<int> &subset, int index)
{
    if (index == nums.size())
    {
        cout << "[";
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i];
            if (i + 1 < subset.size())
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
        return;
    }

    // Include the current element
    subset.push_back(nums[index]);
    printSubsets(nums, subset, index + 1);

    // Exclude the current element
    subset.pop_back();
    printSubsets(nums, subset, index + 1);
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<int> subset;

    cout << "All subsets of the given set are:" << endl;
    printSubsets(nums, subset, 0);

    return 0;
}