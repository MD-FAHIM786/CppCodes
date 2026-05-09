#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Check if it's safe to place a queen at the given position
bool isSafe(vector<string> &board, int row, int col, int n) //O(n) time complexity
    {
        // horizontal
        for (int j = 0; j < n; j++)
        {
            if (board[row][j] == 'Q')
                return false;
        }

        // vertical
        for (int i = 0; i < n; i++)
        {
            if (board[i][col] == 'Q')
                return false;
        }

        // left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        // right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }
// Backtracking function to place queens on the board
    void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans)//O(n^n) time complexity
    {
        if (row == n)
        {
            ans.push_back({board});
            return;
        }

        for (int j = 0; j < n; j++)
        {
            if (isSafe(board, row, j, n))
            {
                board[row][j] = 'Q';
                nQueens(board, row + 1, n, ans);
                board[row][j] = '.';
            }
        }
    }
// Main function to solve the N-Queens problem
    vector<vector<string>> solveNQueeens(int n) //O(n^n) time complexity
    {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        nQueens(board, 0, n, ans);
        return ans;
    }
};
// Main function to read input and display the solutions
int main() //O(n^n) time complexity
{
    int n;
    cin >> n;

    Solution sol;
    vector<vector<string>> ans = sol.solveNQueeens(n);

    for (const auto &solution : ans)
    {
        for (const auto &row : solution)
        {
            cout << row << endl;
        }
        cout << endl; // Separate different solutions with a blank line
    }

    return 0;
}