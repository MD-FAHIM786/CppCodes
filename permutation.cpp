#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution
{
public:
    void getPerm(vector<string> &alp, int idx, vector<vector<string>> &ans)
    {
        if (idx == alp.size())
        {
            ans.push_back({alp});
            return;
        }

        for (int i = idx; i < alp.size(); i++)
        {
            swap(alp[idx], alp[i]); // ith place => ith element choice
            getPerm(alp, idx + 1, ans);

            swap(alp[idx], alp[i]); // backtracking
        }
    }

    vector<vector<string>> permute(vector<string> &alp)
    {
        vector<vector<string>> ans;
        getPerm(alp, 0, ans);
        return ans;
    }
};

int main()
{
    vector<string> alp = {"a", "b", "c"};
    Solution sol;
    vector<vector<string>> ans = sol.permute(alp);
    for (auto &perm : ans)
    {
        for (const string &num : perm)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}