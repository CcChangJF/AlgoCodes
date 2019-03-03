
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution{
    bool valid(int row, int col, int rows, int cols) {
        if (row < 0 || col < 0 || row >= rows || col >= cols) {
            return false;
        }
        else {
            return true;
        }
    }
    void bfs(vector<vector<char> > &board, vector<vector<bool> > &mark,
        int row, int col, int rows, int cols, int &cnt) {
        if (valid(row, col, rows, cols) && '.' == board[row][col] && !mark[row][col]) {
            ++cnt;
            mark[row][col] = true;
            bfs(board, mark, row + 1, col, rows, cols, cnt);
            bfs(board, mark, row - 1, col, rows, cols, cnt);
            bfs(board, mark, row, col + 1, rows, cols, cnt);
            bfs(board, mark, row, col - 1, rows, cols, cnt);
        }
    }
public:
    int solve(int rows, int cols, int startRow, int startCol, vector<vector<char> > &board) {
        vector<vector<bool> > mark(rows, vector<bool>(cols, false));
        int cnt = 0;
        bfs(board, mark, startRow, startCol, rows, cols, cnt);
        return cnt;
    }
};

int main() {
    Solution s;
    int rows = 0;
    int cols = 0;
    cin >> cols >> rows;
    while(0 != rows && 0 != cols) {
        vector<vector<char> > board(rows, vector<char>(cols, 0));
        int startRow = 0;
        int startCol = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                cin >> board[row][col];
                if ('@' == board[row][col]) {
                    startRow = row;
                    startCol = col;
                    board[row][col] = '.';
                }
            }
        }
        cout << s.solve(rows, cols, startRow, startCol, board) << endl;
        cin >> cols >> rows;
    }

    return 0;
}