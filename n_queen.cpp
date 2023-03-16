#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nqueen(vector<vector<string>> &ans, int col, vector<int> &siderow, vector<int> &down, vector<int> &up, int n, vector<string> &board)
    {

        if (col == n)
        {
            ans.push_back(board);
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (siderow[i] == 0 && down[i + col] == 0 && up[n - 1 + (col - i)] == 0)
                {

                    siderow[i] = 1;
                    down[i + col] = 1;
                    up[n - 1 + (col - i)] = 1;
                    board[i][col] = 'Q';
                    nqueen(ans, col + 1, siderow, down, up, n, board);
                    siderow[i] = 0;
                    down[i + col] = 0;
                    up[n - 1 + (col - i)] = 0;
                    board[i][col] = '.';
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {

        vector<string> board(n);
        string x(n, '.');
        for (int i = 0; i < n; i++)
            board[i] = x;

        vector<vector<string>> ans;

        vector<int> siderow(n, 0);
        vector<int> down(2 * n, 0);
        vector<int> up(2 * n, 0);

        nqueen(ans, 0, siderow, down, up, n, board);
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    cout << "HERE I AM FINDING ALL POSSIBLE SOLUTION FOR A DASHBOARD FOR N QUEEN PROBLEM\n";
    cout << "\t\t**ENTER DASH BOAD SIZE**\nSIZE :- ";
    int n;
    cin >> n;
    vector<vector<string>> ans;
    Solution s;
    ans = s.solveNQueens(n);
    for (auto &i : ans)
    {
        for (auto &j : i)
        {
            cout << j << endl;
        }
        cout << endl;
    }
    return 0;
}
