#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<int>> &board)
    {
        vector<unordered_set<int>> rows(9), cols(9), boxes(9);

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {

                if (board[i][j] == 0)
                    continue;

                int boxIndex = (i / 3) * 3 + (j / 3);

                if (rows[i].count(board[i][j]) ||
                    cols[j].count(board[i][j]) ||
                    boxes[boxIndex].count(board[i][j]))
                {
                    return false;
                }

                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                boxes[boxIndex].insert(board[i][j]);
            }
        }

        return true;
    }
};

int main()
{
    vector<vector<int>> board1 = {
        {1, 4, 7, 0, 0, 0, 0, 0, 3},
        {2, 5, 0, 0, 0, 1, 0, 0, 0},
        {3, 0, 9, 0, 0, 0, 0, 0, 0},
        {0, 8, 0, 0, 2, 0, 0, 0, 4},
        {0, 0, 0, 4, 1, 0, 0, 2, 0},
        {9, 0, 0, 0, 0, 0, 6, 0, 0},
        {0, 0, 3, 0, 0, 0, 0, 0, 9},
        {4, 0, 0, 0, 0, 2, 0, 0, 0},
        {0, 0, 1, 0, 0, 8, 0, 0, 7}};

    vector<vector<int>> board2 = {
        {1, 4, 4, 0, 0, 0, 0, 0, 3},
        {2, 5, 0, 0, 0, 1, 0, 0, 0},
        {3, 0, 9, 0, 0, 0, 0, 0, 0},
        {0, 8, 0, 0, 2, 0, 0, 0, 4},
        {0, 0, 0, 4, 1, 0, 0, 2, 0},
        {9, 0, 0, 0, 0, 0, 6, 0, 0},
        {0, 0, 3, 0, 0, 0, 0, 0, 9},
        {4, 0, 0, 0, 0, 2, 0, 0, 0},
        {0, 0, 1, 0, 0, 8, 0, 0, 7}};

    Solution solution;
    cout << "Board 1 is " << (solution.isValidSudoku(board1) ? "valid" : "invalid") << endl;
    cout << "Board 2 is " << (solution.isValidSudoku(board2) ? "valid" : "invalid") << endl;

    return 0;
}
